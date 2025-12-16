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
//题解：树状数组维护逆序对个数
int T=1;
int n;
int a[MAX_N],b[MAX_N];
ll BIT[MAX_N];

inline int lowbit(int x){
	return x&-x;
}

inline void add(int x,ll v){
	for(;x<=n;x+=lowbit(x))
		BIT[x]+=v;
}

inline ll sum(int x){
	ll res=0;
	for(;x>0;x-=lowbit(x))
		res+=BIT[x];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
		sort(b+1,b+n+1);
		ll ans=0;
		for(int i=1;i<=n;i++){
			int rank=lower_bound(b+1,b+n+1,a[i])-b;
			ans+=(sum(n)-sum(rank));
			add(rank,1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}