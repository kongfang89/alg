### 一、概念

**Tarjan算法**是用来求连通图割点的算法。

割点：将该点及与其相连的边从图中去除，使得图不再连通的点就是割点。

### 二、算法实现

选定根节点，从根$dfs$遍历整个图。

1. 判断根节点是否为割点：

    统计子树数目，如果子树数目有2棵及以上，则去除该点会产生两个连通分量，是割点。

2. 判断非根节点是否为割点：

    维护数组$dfn$​和$low$​，表示每个节点的被$dfs$访问的次序和该节点能返回(不能从父节点返回)的$dfn$最小的点(即$dfs$​​​最早访问的点)的$dfn$值。

    计算$dfn$​：对图$dfs$​遍历的时候打标记即可

    计算$low$​：遍历所有边$edge(u,v)$

    - 对于$u$节点，默认$low[u]=dfn[u]$，即最坏情况只能回溯到自己
    - 若子节点$v$未访问，对其$dfs$完后，更新$low[u]=min(low[u], low[v])$​
    - 若节点$v$​（非$u$​的子节点）已访问，说明$dfn[v]<dfn[u]$，无需继续$dfs$，更新$low[u]=min(low[u], dfn[v])$​

    判断割点：

    在每次递归后，对于$u$​的子节点$v$​，如果有$low[v]>=dfn[u]$​​，说明$v$​作为子节点能回溯到的最早的点都在$u$​​之后，则去掉$u$​​节点会使得$v$​唯一一条能到$u$​之前的路径被中断，也即图不连通，此时$u$​是割点。

### 三、代码

```c++
#include <bits/stdc++.h>
#define INF 99999999
#define LINF LLONG_MAX
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=100010;

int n,m;
int cnt,head[MAX_N];
//dfs序，割点数，是否割点标记 
int idx,tot,cut[MAX_N];
//dfs序数组，记录最早能访问到的节点 
int dfn[MAX_N],low[MAX_N];

struct node{
	int to,next;
}edge[MAX_N*2];

void add(int x,int y){
	edge[++cnt].to=y;
	edge[cnt].next=head[x];
	head[x]=cnt;
}

void tarjan(int u,int fa){
	//记录访问次序 
	dfn[u]=low[u]=++idx;
	int child=0;
	//遍历u的子节点 
	for(int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].to;
		//如果还没访问 
		if(!dfn[v]){
			//递归dfs遍历 
			tarjan(v,fa);
			//更新一下u的最早能访问到的节点 
			low[u]=min(low[u],low[v]);
			//如果v最先能访问到的节点的时间>=u自己的时间
			//则说明v最先能访问到的节点都在u后面，则u是割点(u不为根时) 
			if(low[v]>=dfn[u]&&u!=fa)
				cut[u]=1;
			//如果是根节点，统计子树数目 
			else if(u==fa)
				child++;
		}
		//更新一下u的最早能访问到的节点 
		low[u]=min(low[u],dfn[v]);
	}
	//若u的子树数目>=2且为根节点，则u是割点 
	if(child>=2&&u==fa)
		cut[u]=1;
}

int main(){
	freopen("1.in","r",stdin);
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	//freopen("1.out","w",stdout);
	memset(dfn,0,sizeof(dfn));
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	//dfs搜索 
	for(int i=1;i<=n;i++)
		if(dfn[i]==0)
			tarjan(i,i);
	//统计割点数并输出 
	for(int i=1;i<=n;i++)
		if(cut[i])
			tot++;
	cout<<tot<<'\n';
	for(int i=1;i<=n;i++)
		if(cut[i])
			cout<<i<<' ';
	cout<<'\n';
	return 0;
}

/*
样例
6 7
1 2
1 3
1 4
2 5
3 5
4 5
5 6
输出
1
5
*/
```

