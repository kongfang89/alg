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
const int MAX_N = 2e5+10;

int T=1;
int n,a[MAX_N];
map<int,int> mp1,mp2;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            mp1[a[i]+i]++;
            if(i-a[i]>0)
                mp2[i-a[i]]++;
        }
        ll ans=0;
        for(auto [x,y]:mp1){
            if(mp2[x]>0)
                ans+=1ll*y*mp2[x];
        }
        cout<<ans<<'\n';
	}
	return 0;
}