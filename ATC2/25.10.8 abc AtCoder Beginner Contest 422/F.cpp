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
const int MAX_N = 5010;

int T=1;
int n,m;
vector<int> G[MAX_N];
ll w[MAX_N],dp[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>w[i];
		for(int i=1;i<=m;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<=n;i++)
			dp[1][i]=1ll*i*w[1];
		for(int i=n;i;i--)
			for(int u=1;u<=n;u++)
				for(auto v:G[u])
					dp[v][i-1]=min(dp[v][i-1],dp[u][i]+w[v]*(i-1));
		for(int i=1;i<=n;i++)
			cout<<dp[i][0]<<'\n';
	}
	return 0;
}