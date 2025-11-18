#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 5010;
/*题解：
拆点建图，每个点拆成两个点，i拆为inpoint(i)=i*2和outpoint(i)=i*2+1，则原来的nn个点变为nn*2个点，范围为2~2*nn+1，设s=1，t=2*nn+2
对于原本的每条边u-v，添加两条边outpoint(u)->inpoint(v)和outpoint(v)->inpoint(u)，容量为INF
对于原本的每个点i，添加一条边inpoint(i)->outpoint(i)，容量为1
对于原本的源点1，添加两条边s->inpoint(1)和s->outpoint(1)，容量为INF
对于原本的汇点2，添加两条边inpoint(2)->t和outpoint(2)->t，容量为INF
设置成INF的边是为了保证它们不会成为最小割的一部分，因为题目要求坏掉的是设备，不是设备之间的连接
求最小割问题可以转化为求最大流问题，使用Dinic算法求最大流
*/
int T=1;
int head[MAX_N],to[MAX_N],nxt[MAX_N],w[MAX_N],cnt;
int layer[MAX_N],work[MAX_N],n,m,s,t;

int inpoint(int x){
	return x*2;
}

int outpoint(int x){
	return x*2+1;
}

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
	int nn,mm;
	while(cin>>nn>>mm){
		memset(head,-1,sizeof(head));
		cnt=0;
		n=2*nn+2;
		m=mm;
		s=1;
		t=n;
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			add_edge(outpoint(u),inpoint(v),INF);
			add_edge(outpoint(v),inpoint(u),INF);
		}
		for(int i=1;i<=nn;i++)
			add_edge(inpoint(i),outpoint(i),1);
		add_edge(s,inpoint(1),INF);
		add_edge(s,outpoint(1),INF);
		add_edge(inpoint(2),t,INF);
		add_edge(outpoint(2),t,INF);
		cout<<Dinic()<<'\n';
	}
	return 0;
}
