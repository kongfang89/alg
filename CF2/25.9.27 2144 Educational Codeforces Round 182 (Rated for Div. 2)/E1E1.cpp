#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// const int mod = 1e9+7;
const int mod = 998244353;
const int MAX_N = 5e3+10;

int T=1;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
        int n;
		cin>>n;
		vector<int> a(n+1),L(n+1),R(n+1);
		vector<vector<int>> dp1(n+1,vector<int>(n+1)),dp2(n+2,vector<int>(n+2));
        for(int i=1;i<=n;i++)
			cin>>a[i];
		int ma=0;
		int cntl=0,cntr=0;
		for(int i=1;i<=n;i++)
			if(ma<a[i]){
				L[++cntl]=a[i];
				ma=a[i];
			}
		ma=0;
		for(int i=n;i;i--)
			if(ma<a[i]){
				R[++cntr]=a[i];
				ma=a[i];
			}
		dp1[0][0]=dp2[n+1][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=cntl;j>=0;j--){
				if(L[j]==a[i])
					dp1[i][j]=(dp1[i-1][j]*2%mod+dp1[i-1][j-1])%mod;
				else if(L[j]>a[i])
					dp1[i][j]=dp1[i-1][j]*2%mod;
				else
					dp1[i][j]=dp1[i-1][j];
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=cntr;j>=0;j--){
				if(R[j]==a[i])
					dp2[i][j]=(dp2[i+1][j]*2%mod+dp2[i+1][j-1])%mod;
				else if(R[j]>a[i])
					dp2[i][j]=dp2[i+1][j]*2%mod;
				else
					dp2[i][j]=dp2[i+1][j];
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=ma)
				continue;
			ans=(ans+1ll*((dp1[i][cntl]-dp1[i-1][cntl]+mod)%mod)*dp2[i+1][cntr-1]%mod)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}