#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 10;

int T=1;
int n,m;
int a[MAX_N];
int dp[MAX_N][(1<<7)+5];
int ans;

int check(int x,int y){
	int tx=0,ty=0;
	while(x&&y){
		int nx=x%2,ny=y%2;
		if(tx&&nx&&ty&&ny)
			return 1;
		tx=nx,ty=ny;
		x/=2,y/=2;
	}
	return 0;
}

int popcount(int x){
	int res=0;
	while(x){
		res+=x%2;
		x/=2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			a[i]=0;
			for(int j=0;j<m;j++){
				char c;
				cin>>c;
				if(c=='#')
					a[i]|=(1<<j);
			}
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<(1<<m);j++)
				dp[i][j]=INF;
		dp[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<m);j++){
				if((j|a[i])!=a[i])
					continue;
				for(int last=0;last<(1<<m);last++){
					if((last|a[i-1])!=a[i-1])
						continue;
					if(check(j,last))
						continue;
					dp[i][j]=min(dp[i][j],dp[i-1][last]+popcount(j^a[i]));
				}
			}
		}
		ans=INF;
		for(int i=0;i<(1<<m);i++)
			ans=min(ans,dp[n][i]);
		cout<<ans<<'\n';
	}
	return 0;
}