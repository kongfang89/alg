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
const int MAX_N = 100;

int T=1;
int n;
int a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        vector<vector<int>> dp(n+10,vector<int>(2,0));
        for(int i=n;i>=1;i--){
            if(i==n){
                dp[i][0]=a[i];
                dp[i][1]=0;
            } 
            else{
                int res1=a[i]+dp[i+1][1];
                int res2=dp[i+1][0];
                dp[i][0]=max(res1, res2);
                res1=dp[i+1][0];
                res2=a[i]+dp[i+1][1];
                dp[i][1]=min(res1, res2);
            }
        }
        cout<<sum-dp[1][0]<<" "<<dp[1][0]<<'\n';
	}
	return 0;
}