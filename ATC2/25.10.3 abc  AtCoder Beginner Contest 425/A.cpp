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

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i&1){
                ans-=i*i*i;
            }
            else{
                ans+=i*i*i;
            }
        }
        cout<<ans<<'\n';
	}
	return 0;
}