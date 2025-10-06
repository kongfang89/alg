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
const int MAX_N = 1e5+10;

int T=1;
int n,k,x;
int a[MAX_N];
map<long double,ll> mp;
long double ans;
priority_queue<pair<long double,ll>> q;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k>>x;
		mp.clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],mp[a[i]]++;
		while(!q.empty())
			q.pop();
		for(auto i:mp)
			q.push(i);
		while(k){
			auto [i,j]=q.top();
			q.pop();
			if(j>k){
				q.push({i,j-k});
				q.push({i/2.0,k*2});
				k=0;
				break;
			}
			q.push({i/2.0,j*2});
			k-=j;
		}
		while(x){
			auto [i,j]=q.top();
			q.pop();
			if(j>=x){
				ans=i;
				x=0;
				break;
			}
			x-=j;
		}
		cout<<fixed<<setprecision(10)<<ans<<'\n';
	}
	return 0;
}