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
const int MAX_N = 2e5+10;

int T=1;
ll n,k,a[MAX_N],dp[MAX_N][10][5],tmp[10][5],ans;
vector<int> G[MAX_N];

void change(int u,int v){
    memset(tmp,-0x3f,sizeof(tmp));
    for(int i=0;i<=k;i++){
        for(int j=0;j<=k;j++){
            if(i+j<=k)
                for(int p=0;p<3;p++)
                    for(int q=0;q<3;q++)
                        tmp[i+j][p]=max(tmp[i+j][p],dp[u][i][p]+dp[v][j][q]);
            if(i+j<=k)
                tmp[i+j][1]=max(tmp[i+j][1],dp[u][i][0]+dp[v][j][1]+a[u]);
            if(i+j>0&&i+j-1<=k)
                tmp[i+j-1][2]=max(tmp[i+j-1][2],dp[u][i][1]+dp[v][j][1]);
        }
    }
    for(int i=0;i<=k;i++)
        for(int j=0;j<3;j++)
            dp[u][i][j]=max(dp[u][i][j],tmp[i][j]);
}

void dfs(int u,int fa){
    dp[u][0][0]=0;
    dp[u][1][1]=a[u];
    dp[u][1][2]=a[u];
    for(auto v:G[u]){
        if(v==fa)
            continue;
        dfs(v,u);
        change(u,v);
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(dp,-0x3f,sizeof(dp));
        dfs(1,0);
        ans=-0x3f3f3f3f3f3f3f;
        for(int i=0;i<=k;i++)
            for(int j=0;j<3;j++)
                ans=max(ans,dp[1][i][j]);
        cout<<ans<<'\n';
	}
	return 0;
}