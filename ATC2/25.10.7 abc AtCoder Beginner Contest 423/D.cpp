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
const int MAX_N = 3e5+10;

int T=1;
ll n,k;
ll a[MAX_N],b[MAX_N],c[MAX_N],ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i]>>b[i]>>c[i];
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        ll now=0,sum=0;
        for(int i=1;i<=n;i++){
            now=max(now,a[i]);
            while(sum+c[i]>k){
                pair<ll,ll> x=pq.top();
                pq.pop();
                now=max(now,x.first);
                sum-=x.second;
            }
            ans[i]=now;
            pq.push({now+b[i],c[i]});
            sum+=c[i];
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<'\n';
	}
	return 0;
}