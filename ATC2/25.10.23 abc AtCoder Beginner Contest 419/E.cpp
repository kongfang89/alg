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
const int MAX_N = 510;

int T=1;
int n,m,l;
int a[MAX_N];
int dp[MAX_N][MAX_N],v[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m>>l;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=l;i++)
			for(int j=0;j<m;j++)
				for(int k=i;k<=n;k+=l)
					v[i][j]+=(j+m-a[k])%m;
		memset(dp,0x3f,sizeof(dp));
        dp[0][0]=0;
		for(int i=0;i<l;i++)
			for(int j=0;j<m;j++)
				for(int k=0;k<m;k++)
					dp[i+1][(j+k)%m]=min(dp[i+1][(j+k)%m],dp[i][j]+v[i+1][k]);
		cout<<dp[l][0]<<'\n';
	}
	return 0;
}