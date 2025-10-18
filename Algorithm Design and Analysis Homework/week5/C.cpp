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
const int MAX_N = 1e3+10;
/*题解：
dp[i]表示以a[i]结尾的最长上升子序列长度
*/
int T=1;
int n,b;
int a[MAX_N],dp[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>b){
		a[1]=b;
		for(int i=2;i<=n;i++)
			a[i]=1LL*(a[i-1]+1)*(a[i-1]+1)%mod;
		int ans=0;
		for(int i=1;i<=n;i++){
			dp[i]=1;
			for(int j=1;j<i;j++)
				if(a[j]<a[i]&&dp[j]+1>dp[i])
					dp[i]=dp[j]+1;
			ans=max(ans,dp[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}