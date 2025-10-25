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
const int MAX_N = 2e4+10;
//题解：由于每一对数都是取min，则最小的数一定会被取，让次小的数和它配对，则次小的数不会被取，故从小到大排序，两两一组即可
int T=1;
int n;
int a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		n<<=1;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i+=2)
			ans+=a[i];
		cout<<ans<<'\n';
	}
	return 0;
}