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
int n,q;
ll a[MAX_N],s[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>q;
		ll ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		for(int i=1;i<=q;i++){
			ll b;
			cin>>b;
			if(b>ma){
				cout<<-1<<endl;
				continue;
			}
			int id=lower_bound(a+1,a+n+1,b-1)-a-1;
			ll ans=s[id]+(n-id)*(b-1)+1;
			cout<<ans<<'\n';
		}
	}
	return 0;
}