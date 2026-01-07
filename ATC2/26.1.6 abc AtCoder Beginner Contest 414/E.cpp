#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// const int mod = 1e9+7;
const ll mod = 998244353;
const int MAX_N = 1;

int T=1;
ll n;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        ll ans=0;
        ans=((((n-2)%mod)*((n+1)%mod))%mod*((mod+1)/2))%mod;
        ll l=2;
        while(l<n){
            ll k=n/l;
            ll L=min(n/k+1,n);
            ans=(ans+mod-((L-l)%mod)*(k%mod)%mod)%mod;
            l=L;
        }
        cout<<ans<<'\n';
	}
	return 0;
}