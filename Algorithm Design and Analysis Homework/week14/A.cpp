#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1e5+10;
//题解：线段树维护区间最大值
int T=1;
ll n,m,a[MAX_N];
ll tr[MAX_N<<2];

inline void pushup(ll x){
	tr[x]=max(tr[ls],tr[rs]);
}

void build(ll x,ll l,ll r){
	if(l==r){
		tr[x]=a[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(x);
}

void update(ll x,ll id,ll l,ll r,ll k){
	if(l==r){
		tr[x]=k;
		return;
	}
	if(id<=mid)
		update(ls,id,l,mid,k);
	else
		update(rs,id,mid+1,r,k);
	pushup(x);
}

ll query_max(ll x,ll nl,ll nr,ll l,ll r){
	if(nr<l||nl>r)
		return -LINF;
	if(nl<=l&&nr>=r)
		return tr[x];
	return max(query_max(ls,nl,nr,l,mid),query_max(rs,nl,nr,mid+1,r));
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		build(1,1,n);
		while(m--){
			int op;
			cin>>op;
			if(op==1){
				ll id,x;
				cin>>id>>x;
				update(1,id+1,1,n,x);
			}
			else{
				ll l,r;
				cin>>l>>r;
				cout<<query_max(1,l+1,r+1,1,n)<<'\n';
			}
		}
	}
	return 0;
}