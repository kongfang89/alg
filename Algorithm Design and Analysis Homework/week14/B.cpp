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

int T=1;
ll n,m,a[MAX_N];
ll tr[MAX_N<<2],addi[MAX_N<<2];

inline void pushup(ll x){
	tr[x]=(tr[ls]+tr[rs]);
}

inline void pushdown(ll x,ll l,ll r){
	if(addi[x]==0)
		return;
	tr[ls]=tr[ls]+addi[x]*(mid-l+1);
	tr[rs]=tr[rs]+addi[x]*(r-mid);
	addi[ls]=addi[ls]+addi[x];
	addi[rs]=addi[rs]+addi[x];
	addi[x]=0;
}

void build(ll x,ll l,ll r){
	addi[x]=0;
	if(l==r){
		tr[x]=a[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(x);
}

inline void add(ll x,ll nl,ll nr,ll l,ll r,ll k){
	if(nr<l||nl>r)
		return;
	if(nl<=l&&nr>=r){
		addi[x]=(addi[x]+k);
		tr[x]=(tr[x]+k*(r-l+1));
		return;
	}
	pushdown(x,l,r);
	add(ls,nl,nr,l,mid,k);
	add(rs,nl,nr,mid+1,r,k);
	pushup(x);
}

ll query(ll x,ll nl,ll nr,ll l,ll r){
	if(nr<l||nl>r)
		return 0;
	if(nl<=l&&nr>=r)
		return tr[x];
	pushdown(x,l,r);
	return (query(ls,nl,nr,l,mid)+query(rs,nl,nr,mid+1,r));
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
			ll op,l,r,k;
			cin>>op;
			if(op==1){
				cin>>l>>r>>k;
				l++;
				r++;
				add(1,l,r,1,n,k);
			}
			else{
				cin>>l>>r;
				l++;
				r++;
				cout<<query(1,l,r,1,n)<<'\n';
			}
		}
	}
	return 0;
}