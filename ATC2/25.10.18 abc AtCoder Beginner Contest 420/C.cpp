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
int n,q;
int a[MAX_N],b[MAX_N],mi[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>q;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=min(a[i],b[i]);
        }
        for(int i=0;i<q;i++){
            char c;
            int x,v;
            cin>>c>>x>>v;
            if(c=='A'){
                ans-=min(a[x-1],b[x-1]);
                a[x-1]=v;
                ans+=min(a[x-1],b[x-1]);
            }
            else{
                ans-=min(a[x-1],b[x-1]);
                b[x-1]=v;
                ans+=min(a[x-1],b[x-1]);
            }
            cout<<ans<<'\n';
        }
	}
	return 0;
}