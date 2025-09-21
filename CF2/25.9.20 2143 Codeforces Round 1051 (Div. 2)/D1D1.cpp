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
const int MAX_N = 3000+10;

int T=1;
int n;
int a[MAX_N],b[MAX_N];
int dp[2][MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++){
			a[i]=1;
			for(int j=1;j<i;j++)
				if(b[j]<=b[i])
					a[i]++;
			for(int j=i+1;j<=n;j++)
				if(b[j]<b[i])
					a[i]++;
		}
		for(int i=0;i<2;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					dp[i][j][k]=0;
		dp[0][0][0]=1;
		int f=0;
		for(int i=1;i<=n;i++){
			f^=1;
			int x=a[i];
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
					dp[f][j][k]=dp[f^1][j][k];
			for(int j=0;j<=n;j++)
				for(int k=0;k<=j;k++){
					if(dp[f^1][j][k]==0)
						continue;
					if(j>x&&x>k)
						dp[f][j][x]=(dp[f][j][x]+dp[f^1][j][k])%mod;
					else if(x>j)
						dp[f][x][k]=(dp[f][x][k]+dp[f^1][j][k])%mod;
				}
		}
		int ans=0;
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				ans=(ans+dp[f][j][k])%mod;
		cout<<ans<<'\n';
	}
	return 0;
}