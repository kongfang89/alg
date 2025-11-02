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
const int MAX_N = 1010;

int T=1;
int n,m,s,t,M[MAX_N][MAX_N],vis[MAX_N],ans[MAX_N],cnt,path[MAX_N];

void dfs(int now,int u){
    if(u==t){
        cnt=now;
        for(int i=1;i<=cnt;i++)
            ans[i]=path[i];
        return;
    }
    for(int i=1;i<=n;i++){
        if(!M[u][i])
            continue;
        if(vis[i])
            continue;
        vis[i]=1;
        path[now+1]=i;
        dfs(now+1,i);
        path[now+1]=0;
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>t;
        memset(M,0,sizeof(M));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            M[u][v]=1;
            M[v][u]=1;
        }
        vis[s]=1;
        path[1]=s;
        dfs(1,s);
        for(int i=1;i<=cnt;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
	}
	return 0;
}