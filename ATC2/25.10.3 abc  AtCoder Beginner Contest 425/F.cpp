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
const int MAX_N = (1<<25);

int T=1;
ll n;
string s;
ll dp[MAX_N];

ll f(ll x){
	if(!x)
		return 1;
	if(dp[x])
		return dp[x];
	ll res=0;
	int last=-1;
	for(int i=n-1;i>=0;i--){
		if((x>>i)&1){
			if(last==-1||s[n-i-1]!=s[last])
				res=(res+f(x-(1ll<<i)))%mod;
			last=n-i-1;
		}
	}
	return dp[x]=res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>s;
		ll ans=f((1ll<<n)-1);
		cout<<ans<<'\n';
	}
	return 0;
}