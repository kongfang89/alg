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

ll solve(ll x,ll n){
	if(n==0){
		return 1;
	}
	ll t=solve(x,n-1);
	return t+t*x;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	ll x, n;
    while(cin>>x>>n)
    {
        cout<<solve(x,n)<<endl;
    }
	return 0;
}