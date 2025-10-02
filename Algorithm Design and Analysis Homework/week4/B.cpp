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
const int MAX_N = 1e5+10;

int T=1;
int n;
int a[MAX_N];
int dp[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>a[i],dp[i]=0;
		int ans=-100000000;
		for(int i=1;i<=n;i++){
			dp[i]=max(dp[i-1]+a[i],a[i]);
			ans=max(ans,dp[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}