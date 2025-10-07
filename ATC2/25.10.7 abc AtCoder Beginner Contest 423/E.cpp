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
const int MAX_N = 3e5+10;

int T=1;
int n,q;
ll a[MAX_N];
ll s2[MAX_N],s1[MAX_N],s0[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>q;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++){
			s0[i]=s0[i-1]+a[i];
			s1[i]=s1[i-1]+a[i]*i;
			s2[i]=s2[i-1]+a[i]*i*i;
		}
		for(int i=1;i<=q;i++){
			ll l,r;
			cin>>l>>r;
			ll ans=-(s2[r]-s2[l-1])+(l+r)*(s1[r]-s1[l-1])+(-l+1)*(r+1)*(s0[r]-s0[l-1]);
			cout<<ans<<'\n';
		}
	}
	return 0;
}