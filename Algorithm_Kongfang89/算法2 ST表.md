### 一、概念

**ST表**基于倍增的思想，可以维护**静态区间最值**，预处理复杂度为$O(nlogn)$，查询复杂度为$O(1)$

整体上，**ST表**的复杂度优于树状数组、线段树，但是不能解决在线修改的问题

### 二、算法实现

定义$st[i][j]$表示区间$[i,i+2^{j}-1]$​的最大值，$i$表示左端点，$j$表示从左端点起多少个元素

利用以下递推式可以在$O(nlogn)$的复杂度实现预处理

1. $st[i][0]=a_{i}$
2. $st[i][j]=max(st[i,j-1],st[i+2^{j-1}][j-1])$

查询$[l,r]$的最大值，只需查询$max(st[l][l+2^s-1],st[r-2^s+1][r])$

其中$s=\lfloor log_{2}(r-l+1) \rfloor$，关于$log$的计算也可以预处理出来

### 三、代码模板

```c++
#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=100010;
//输入的n个数，m次查询
int n,m; 
//st[i][j]，log计算
int f[MAX_N][21],logn[MAX_N];
//快读
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') 
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
//预处理
void pre(){
	logn[1]=0;
	logn[2]=1;
	for(int i=3;i<MAX_N;i++){
		logn[i]=logn[i/2]+1;
	}
} 
 
int main(){
	freopen("1.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		f[i][0]=read();
	}
	pre();
	for(int j=1;j<=21;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int x,y;
		x=read(),y=read();
		int s=logn[y-x+1];
		printf("%d\n",max(f[x][s],f[y-(1<<s)+1][s]));
	}
	return 0;
}

/*
样例
8 8
9 3 1 7 5 6 0 8
1 6
1 5
2 7
2 6
1 8
4 8
3 7
1 8
输出
9
9
7
7
9
8
7
9
*/
```

### 四、题单

- [P3865](https://www.luogu.com.cn/problem/P3865) ST表【模板】