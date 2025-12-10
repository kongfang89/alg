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
//题解：动态规划，dp[i][j]表示以(i,j)为右下角的最大正方形边长，如果a[i][j]=0则dp[i][j]=0，否则dp[i][j]=min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+1
int T=1;
int n,m;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	while(cin>>n){
        if(!n)
            break;
        cin>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        memset(dp,0,sizeof(dp));
        int ma=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==1){
                    dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                    ma=max(ma,dp[i][j]);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        cout<<ma*ma<<endl;
	}
	return 0;
}