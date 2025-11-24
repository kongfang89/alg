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
ll n,m;
struct node{
    ll x,y,d;
}a[MAX_N];

int cmp(node a,node b){
    if(a.d==b.d)
        return a.x<b.x;
    return a.d<b.d;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=1;i<=m;i++){
            ll x,y;
            cin>>x>>y;
            a[i]={x,y,x-y};
        }
        sort(a+1,a+m+1,cmp);
        ll ans=0;
        for(int i=1;i<=m;i++){
            if(a[i].x>n)
                continue;
            ll t=(n-a[i].y)/a[i].d;
            ans+=t;
            n-=t*a[i].d;
        }
        cout<<ans<<'\n';
	}
	return 0;
}