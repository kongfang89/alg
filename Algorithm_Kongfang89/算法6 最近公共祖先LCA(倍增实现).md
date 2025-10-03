### 一、概念

**最近公共祖先(Least Common Ancestors, LCA)**指的是在一棵有根树中，两个节点$u$和$v$的最近公共祖先。

### 二、算法实现

求解树上任意两个节点的$LCA$​，有多种算法，$BF$​显然是会超时的，本文介绍**倍增算法**求解$LCA$​

倍增算法也即每次按$2^{k}$增加，$BF$求解$LCA$的方式是逐个向上找父节点，而倍增可以加速这一步骤，从而降低复杂度。

需要注意：这里的倍增是从$2^{k}$​往$2^{0}$​走，可以避免跳过头的情况。

**预处理每个节点的$2$​​​的$[0,k]$​​​​次幂级祖先节点：**

理解了倍增后，我们需要先预处理出每个节点的$2$的$[0,k]$次幂级祖先节点，以便快速查询，这里我们用一个二维数组$f[][]$存放每个节点的祖先节点信息，$f[i][j]$表示节点$i$的$2^{j}$级的祖先，即节点$i$往上走$2^{j}$​步的节点编号。

显然有以下两个式子计算$f$数组：

- $f[i][j]=$​​​ 节点$i$​​​​的父节点 $(j=0)$​​​
- $f[i][j]=f[f[i][j-1]][j-1]$​ $(j>0)$

2式的含义为：节点$i$的$2^{j}$级祖先是节点$i$的$2^{j-1}$级祖先的$2^{j-1}$级祖先

关于取值范围，显然有$i \in [1,n]$​​，那$j$​​的取值范围是多少呢？如果画出树的图，比较容易看出节点$i$​​的祖先节点共有$dep[i]-1$​​个，$dep[i]$​​表示节点$i$​​​​​的深度，所以对于节点$i$​​，我们需要遍历的$j \in [1,log_{2}(dep[i]-1)]$​​​，这里​的$log_{2}$​​​运算也可以预处理出来。

这一部分用$dfs$从根搜索一下整棵树，边搜边记录$dep$和$f$数组就可以实现啦。

**$LCA$的实现：**

下面讲讲$LCA$​​​的具体实现，首先，对于$LCA(u,v)$​​​，不妨假设$dep[u]>=dep[v]$​​​，我们先让$u$​​​跳到和$v$​​​一样的深度，也即循环$u=f[u][log_{2}(dep[u]-dep[v])]$​​​，此时，如果$u==v$​​​，说明$LCA(u,v)=u$​​​；否则，继续向上跳，跳的步长从$2^{log_{2}(dep[u]-1)}$​​​到$2^{0}$​​​，如果这一次$u,v$​​​要跳到的两个节点的相同，则说明跳过头了，这次不跳，如果要跳到的两个节点不同就跳，最后跳到的两个节点的父节点就是$LCA(u,v)$​​​​，也即最后$u,v$​​​会跳到节点$LCA(u,v)$​​​的下一层

### 三、代码

```c++
#include <bits/stdc++.h>
#define INF 99999999
#define LINF LLONG_MAX
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=500010;

int n,m,s;
int dep[MAX_N],f[MAX_N][30],logg[MAX_N];

struct node{
	int v,next;
}edge[MAX_N<<1];
int head[MAX_N],cnt;

void add(int u,int v){
	edge[++cnt].v=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}

void dfs(int u,int fa){
	//u的2^0级祖先节点就是其父节点 
	f[u][0]=fa;
	//子节点的高度=父节点的高度+1 
	dep[u]=dep[fa]+1;
	//递推出u的所有2的次幂级祖先节点，即2^1级到2^(dep[u]-1)级，logg[dep[u]-1]要-1是因为logg存的是log(i)+1 
	for(int i=1;i<=logg[dep[u]-1]-1;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	//遍历所有子节点继续dfs 
	for(int i=head[u];i!=0;i=edge[i].next)
		if(edge[i].v!=fa)
			dfs(edge[i].v,u);
}

int LCA(int u,int v){
	//让dep[u]>=dep[v] 
	if(dep[u]<dep[v])
		swap(u,v);
	//先让u跳到和v一样的高度，logg[dep[u]-dep[v]]要-1是因为logg存的是log(i)+1 
	while(dep[u]>dep[v])
		u=f[u][logg[dep[u]-dep[v]]-1];
	//如果u直接跳到v，说明v就是LCA(u,v) 
	if(u==v)
		return u;
	//否则同时往上跳，跳的步长从2^(dep[u]-1)到2^0，最后会跳到LCA(u,v)的下一层 
	for(int i=logg[dep[u]-1]-1;i>=0;i--)
		//如果跳到的两个新节点相等，则不跳
		//否则就跳，即更新u,v 
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	//最后返回跳到的节点的父节点即时LCA(u,v) 
	return f[u][0];
}

int main(){
	freopen("1.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	//freopen("1.out","w",stdout);
	//输入 
	cin>>n>>m>>s;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	//预处理log(i)+1的值 
	for(int i=1;i<=n;i++)
		logg[i]=logg[i-1]+(1<<logg[i-1]==i);
	//从根节点s搜索 
	dfs(s,0);
	//输出答案 
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		cout<<LCA(u,v)<<'\n';
	}
	return 0;
}

/*
样例
5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5
输出
4
4
1
4
4
*/
```

