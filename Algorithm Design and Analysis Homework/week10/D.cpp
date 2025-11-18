#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 2010;
//题解：求最小割问题可以转化为求最大流问题，使用Dinic算法求最大流，注意无向图需要添加两条边，两个方向都是w
int T=1;
int head[MAX_N],to[MAX_N],nxt[MAX_N],w[MAX_N],cnt;
int layer[MAX_N],work[MAX_N],n,m,s,t;

void add(int u,int v,int _w){
	nxt[cnt]=head[u];
	to[cnt]=v;
	w[cnt]=_w;
	head[u]=cnt++;
}

void add_edge(int u,int v,int w){
	add(u,v,w);
	add(v,u,0);
}

bool DiBFS(){
	queue<int> q;
	memset(layer,-1,sizeof(layer));
	q.push(s);
	layer[s]=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=head[now];i!=-1;i=nxt[i]){
			if(layer[to[i]]>=0||!w[i])
				continue;
			layer[to[i]]=layer[now]+1;
			if(to[i]==t)
				return 1;
			q.push(to[i]);
		}
	}
	return 0;
}

int DiDFS(int now,int inc){
	int tinc;
	if(now==t)
		return inc;
	for(int i=work[now];i!=-1;i=nxt[i]){
		if(w[i]&&layer[to[i]]==layer[now]+1&&(tinc=DiDFS(to[i],min(inc,w[i])))){
			w[i]-=tinc;
			w[i^1]+=tinc;
			return tinc;
		}
	}
	return 0;
}

int Dinic(){
	int res=0,tinc;
	while(DiBFS()){
		for(int i=0;i<=n;i++)
			work[i]=head[i];
		while(tinc=DiDFS(s,t))
			res+=tinc;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>m){
		memset(head,-1,sizeof(head));
		cnt=0;
		s=1;
		t=2;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			add_edge(u,v,w);
			add_edge(v,u,w);
		}
		cout<<Dinic()<<'\n';
	}
	return 0;
}
