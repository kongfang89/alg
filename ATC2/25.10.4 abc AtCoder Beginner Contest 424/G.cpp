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
const int MAX_N = 110;

int n,m;
ll a[MAX_N],cnt[MAX_N],dp[MAX_N][MAX_N*MAX_N];

int T=1;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		vector<pair<ll,ll>> v;
		for(int i=1;i<=m;i++){
			ll b,c;
			cin>>b>>c;
			v.push_back({b,c});
		}
		sort(v.begin(),v.end(),greater<>());
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cnt[i]+=min(a[j],1ll*i);
		for(int i=0;i<=m;i++)
			for(int j=0;j<=n*m;j++)
				dp[i][j]=-1e18;
		dp[0][0]=0;
		for(int i=0;i<m;i++){
			ll b=v[i].first,c=v[i].second;
			for(int k=m;k>=1;k--){
				for(int s=n*m;s>=b;s--){
					if(s<=cnt[k]&&dp[k-1][s-b]!=-1e18)
						dp[k][s]=max(dp[k][s],dp[k-1][s-b]+c);
				}
			}
		}
		ll ans=0;
		for(int i=0;i<=m;i++)
			for(int j=0;j<=n*m;j++)
				ans=max(ans,dp[i][j]);
		cout<<ans<<'\n';
	}
	return 0;
}