#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// const int mod = 1e9+7;
const int mod = 998244353;
const int MAX_N = 2e5+10;

int T=1;
ll n,m,a[MAX_N];

struct node{
	ll sum;
	ll lazy;
}tree[MAX_N<<2];

ll ksm(ll x,ll n){
	ll res=1;
	while(n){
		if(n&1)
			res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}

ll inv(ll x){
	return ksm(x,mod-2);
}

ll ls(ll id){
	return id<<1;
}

ll rs(ll id){
	return id<<1|1;
}

void pushup(ll id,ll l,ll r){
	if(l>=r)
		return;
	tree[id].sum=(tree[ls(id)].sum+tree[rs(id)].sum)%mod;
}

void pushdown(ll id,ll l,ll r){
	if(l>=r)
		return;
	if(tree[id].lazy!=-1){
		ll mid=l+r>>1;
		ll t=tree[id].lazy;
		tree[id].lazy=-1;
		tree[ls(id)].sum=t*(mid-l+1)%mod;
		tree[ls(id)].lazy=t;
		tree[rs(id)].sum=t*(r-mid)%mod;
		tree[rs(id)].lazy=t;
	}
}

void build(ll id,ll l,ll r){
	if(l>r)
		return;
	if(l==r){
		tree[id].sum=a[l];
		tree[id].lazy=-1;
		return;
	}
	ll mid=l+r>>1;
	build(ls(id),l,mid);
	build(rs(id),mid+1,r);
	pushup(id,l,r);
	tree[id].lazy=-1;
}

void update(ll id,ll l,ll r,ll ml,ll mr,ll x){
	if(l>r)
		return;
	if(ml<=l&&r<=mr){
		tree[id].sum=x*(r-l+1)%mod;
		tree[id].lazy=x;
		return;
	}
	ll mid=l+r>>1;
	if(ml<=mid)
		update(ls(id),l,mid,ml,mr,x);
	if(mr>mid)
		update(rs(id),mid+1,r,ml,mr,x);
	pushup(id,l,r);
}

ll query(ll id,ll l,ll r,ll ql,ll qr){
	if(l>r)
		return 0;
	if(ql<=l&&r<=qr)
		return tree[id].sum;
	pushdown(id,l,r);
	ll mid=l+r>>1;
	ll res=0;
	if(ql<=mid)
		res=(res+query(ls(id),l,mid,ql,qr))%mod;
	if(qr>mid)
		res=(res+query(rs(id),mid+1,r,ql,qr))%mod;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		build(1,1,n);
		for(int i=1;i<=m;i++){
			ll l,r;
			cin>>l>>r;
			ll sum=query(1,1,n,l,r);
			ll len=r-l+1;
			ll fac=sum*inv(len)%mod;
			update(1,1,n,l,r,fac);
		}
		for(int i=1;i<=n;i++)
			cout<<query(1,1,n,i,i)<<" ";
		cout<<'\n';
	}
	return 0;
}