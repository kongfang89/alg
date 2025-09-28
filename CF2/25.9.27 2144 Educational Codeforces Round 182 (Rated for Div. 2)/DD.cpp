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
ll n,y,a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>y;
        ll ma=0;
        for(int i=0;i<n;i++)
            cin>>a[i],ma=max(ma,a[i]);
        vector<ll> cnt(ma+1,0),p(ma+1,0);
        for(int i=0;i<n;i++)
            cnt[a[i]]++;
        for(int i=1;i<=ma;i++)
            p[i]=p[i-1]+cnt[i];
        ll ans=-1e18;
        if(ma==1){
            cout<<n<<'\n';
            continue;
        }
        for(ll i=2;i<=ma;i++){
            ll res=0;
            for(ll j=1;j<=ma;j++){
                int l=i*(j-1);
                int r=min(ma,i*j);
                if(l>ma)
                    break;
                int ccnt=p[r]-p[l];
                res+=ccnt*j;
                res-=y*max(0ll,ccnt-cnt[j]);
            }
            ans=max(ans,res);
        }
        cout<<ans<<'\n';
	}
	return 0;
}