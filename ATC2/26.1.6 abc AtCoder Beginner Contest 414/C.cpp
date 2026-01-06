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
const int MAX_N = 1;

int T=1;
ll a,n;

int check(ll x,ll base){
	vector<ll> v;
	while(x){
		v.push_back(x%base);
		x/=base;
	}
	int flag=1;
	for(int i=0;i<v.size();i++){
		if(v[i]!=v[v.size()-1-i]){
			flag=0;
			break;
		}
	}
	return flag;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>a>>n;
		ll ans=0;
		for(ll i=1;i<=n;i++){{
			if(check(i,10ll)&&check(i,a))
				ans+=i;
		}
		cout<<ans<<'\n';
	}
	return 0;
}