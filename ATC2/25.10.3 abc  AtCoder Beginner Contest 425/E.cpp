#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 5010;

int T=1,mod;
int n,a[MAX_N];
int C[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T>>mod;
	for(int i=0;i<=5000;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	while(T--){
		cin>>n;
		int s=0,ans=1;
		for(int i=1;i<=n;i++)
			cin>>a[i],s+=a[i];
		for(int i=1;i<=n;i++){
			ans=1ll*ans*C[s][a[i]]%mod;
			s-=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}