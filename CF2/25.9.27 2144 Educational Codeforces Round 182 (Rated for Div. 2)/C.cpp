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
const int MAX_N = 110;

int T=1;
int n,a[MAX_N],b[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i];
		ll ans=1;
		for(int i=1;i<=n;i++){
			if(a[i]>b[i])
				swap(a[i],b[i]);
			if(i==1||a[i]>=b[i-1])
				ans=(ans*2)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}