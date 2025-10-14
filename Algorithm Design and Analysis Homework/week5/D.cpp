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

int T=1;
string s,t;
int dp[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>s>>t){
        int n=s.size(),m=t.size();
        s=" "+s;
        t=" "+t;
		dp[0][0]=0;
        dp[1][0]=0;
        dp[0][1]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i]==t[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<dp[n][m]<<'\n';
	}
	return 0;
}