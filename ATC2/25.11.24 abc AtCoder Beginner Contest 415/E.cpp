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
const int MAX_N = 4e5+10;

int T=1;
ll n,m,p[MAX_N];
vector<vector<ll>> a,dp;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        a.resize(n+5,vector<ll>(m+5));
        dp.resize(n+5,vector<ll>(m+5));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n+m-1;i++)
            cin>>p[i];
        for(int i=n;i>=1;i--){
            for(int j=m;j>=1;j--){
                dp[i][j]=LINF;
                if(i!=n)
                    dp[i][j]=min(dp[i][j],max(0ll,dp[i+1][j])-(a[i][j]-p[i+j-1]));
                if(j!=m)
                    dp[i][j]=min(dp[i][j],max(0ll,dp[i][j+1])-(a[i][j]-p[i+j-1]));
                if(i==n&&j==m)
                    dp[i][j]=-(a[i][j]-p[i+j-1]);
            }
        }
        cout<<max(0ll,dp[1][1])<<endl;
	}
	return 0;
}