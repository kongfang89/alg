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

int T=1;
int n;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				cin>>a[i][j],dp[i][j]=0;
		int ans=0;
		dp[1][1]=a[1][1];
		for(int i=2;i<=n;i++)
			for(int j=1;j<=i;j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
				ans=max(ans,dp[i][j]);
			}
		cout<<ans<<'\n';
	}
	return 0;
}