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
//题解：a^n=a^(n/2)*a^(n/2)*(n%2==1?a:1)
int T=1;
int a,b,p;

ll ksm(int x,int n){
	ll res=1;
	while(n){
		if(n&1)
			res=(res*a)%p;
		a=(a*a)%p;
		n>>=1;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>a>>b>>p;
		cout<<ksm(a,b)<<'\n';
	}
	return 0;
}