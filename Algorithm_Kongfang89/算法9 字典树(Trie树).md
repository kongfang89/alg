### 一、概念

字典树(Trie树)是一种存字或单词信息的数据结构，可以快速查找字或单词的信息，树上的边通常存放数字或字母等字符信息，而从根节点到叶子节点的所有字符连起来通常是单词这类信息。

### 二、算法原理

经典字典树主要有两种操作：

1. 插入一个单词到集合中
2. 查询单词是否在集合中

#### 具体实现

1. 插入单词

    从单词第一个字母开始，判断树上的根是否有到该字母的边，如果没有就新建一条边和一个节点，并给节点编号；然后更新根为该字母的编号，对剩余字母逐个进行上述操作。操作完后给最后一个字母的编号记录一下访问标记bool。

2. 查询单词

    从单词第一个字母开始，判断树上的根是否有到该字母的边，如果没有就是该单词不在集合中，如果有就更新根为该字母编号，继续查询下一个字母。

### 三、代码

[P3879 阅读理解](https://www.luogu.com.cn/problem/P3879)

```c++
#include <bits/stdc++.h>
#define INF 99999999
#define LINF LLONG_MAX 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=1010;
//输入 
int n,m;
char s[MAX_N];
//节点数 
int tot;
//trie[i][j]表示第i个单词的第j个字母的编号 
int trie[300010][25];
//bool数组：b[i][j]表示以i结尾的是单词，且是第j篇文章的单词 
bitset<MAX_N> b[500010];
//插入单词s 
inline void insert(char *s,int x){
	int root=0;
	//遍历单词的每个字母
	for(int i=0;s[i];i++){ 
		int v=s[i]-'a';
		//如果当前无编号，编号
		if(!trie[root][v])
			trie[root][v]=++tot;
		//移动root到新编号 
		root=trie[root][v];
	}
	//记录最后编号的篇数为1 
	b[root][x]=1;
}
//查询单词 
inline void query(char *s){
	int root=0;
	for(int i=0;s[i];i++){
		int v=s[i]-'a';
		if(!trie[root][v]){
			cout<<" \n";
			return;
		}
		root=trie[root][v];
	}
	for(int i=1;i<=n;i++)
		if(b[root][i]==1)
			cout<<i<<' ';
	cout<<'\n';
}

int main(){
	freopen("1.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	//freopen("1.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>s;
			insert(s,i);
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>s;
		query(s);
	}
	return 0;
}

/*
样例
3
9 you are a good boy ha ha o yeah
13 o my god you like bleach naruto one piece and so do i
11 but i do not think you will get all the points
5
you
i
o
all
naruto
输出
1 2 3
2 3
1 2
3
2
*/
```

