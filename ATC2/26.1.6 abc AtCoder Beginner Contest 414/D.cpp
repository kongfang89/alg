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
const int MAX_N = 5e5+10;

int T=1;
ll n,m;
ll x[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>x[i];
        sort(x+1,x+n+1);
        vector<ll> v;
        for(int i=1;i<n;i++)
            v.push_back(x[i+1]-x[i]);
        sort(v.begin(),v.end());
        ll ans=0;
        for(int i=0;i<n-m;i++)
            ans+=v[i];
        cout<<ans<<'\n';
	}
	return 0;
}