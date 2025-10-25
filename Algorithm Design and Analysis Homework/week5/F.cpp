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
const int MAX_N = 60;

int T=1;
int n,m;
int L[MAX_N];
int dp[MAX_N][MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>m){
        memset(L,0,sizeof(L));
		for(int i=0;i<m;i++){
            int l,r;
            cin>>l>>r;
            L[r]=max(L[r],l);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<=j;k++){
                    if(L[i]<=k){
                        dp[i+1][j][k]=(dp[i+1][j][k]+dp[i][j][k]*6LL)%mod;
                        dp[i+1][i+1][j]=(dp[i+1][i+1][j]+dp[i][j][k]*2LL)%mod;
                        dp[i+1][i+1][i+1]=(dp[i+1][i+1][i+1]+dp[i][j][k]*2LL)%mod;
                    }
                }  
            }
        }
        int ans=0;
        for(int j=0;j<=n;j++){
            for(int k=L[n];k<=j;k++){
                ans=(ans+dp[n][j][k])%mod;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}