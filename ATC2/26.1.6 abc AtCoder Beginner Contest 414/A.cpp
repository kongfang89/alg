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
int n,l,r;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>l>>r;
        int ans=0;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            if(x<=l&&y>=r)
                ans++;
        }
        cout<<ans<<'\n';
	}
	return 0;
}