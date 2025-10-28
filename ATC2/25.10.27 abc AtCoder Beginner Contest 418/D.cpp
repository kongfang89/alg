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
string s;
ll n,sum,ans,t[2];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>s;
		s=" "+s;
		t[0]=1;
		for(int i=1;i<=n;i++){
			sum+=(s[i]=='0');
			ans+=t[sum%2];
			t[sum%2]++;			
		}
		cout<<ans<<'\n';
	}
	return 0;
}