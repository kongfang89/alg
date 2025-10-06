#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#define ls(x) (x<<1)
#define rs(x) ((x<<1)|1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1e6+10;

int T=1;
ll n,m,t1[MAX_N<<2],t2[MAX_N<<2];

void pushup1(ll x){
	t1[x]=max(t1[ls(x)],t1[rs(x)]);
}

void pushup2(ll x){
	t2[x]=min(t2[ls(x)],t2[rs(x)]);
}

void build1(ll x,ll l,ll r){
	if(l==r){
		t1[x]=0;
		return;
	}
	ll mid=(l+r)>>1;
	build1(ls(x),l,mid);
	build1(rs(x),mid+1,r);
	pushup1(x);
}

void build2(ll x,ll l,ll r){
	if(l==r){
		t2[x]=INF;
		return;
	}
	ll mid=(l+r)>>1;
	build2(ls(x),l,mid);
	build2(rs(x),mid+1,r);
	pushup2(x);
}

void update(ll x,ll s,ll l,ll r,ll p){
	if(l==r){
		t1[x]=p;
		t2[x]=p;
		return;
	}
	ll mid=(l+r)>>1;
	if(s<=mid)
		update(ls(x),s,l,mid,p);
	else
		update(rs(x),s,mid+1,r,p);
	pushup1(x);
	pushup2(x);
}

ll query1(ll x,ll L,ll R,ll l,ll r){
	if(L<=l&&R>=r)
		return t1[x];
	ll res=0;
    ll mid=(l+r)>>1;
	if(L<=mid)
		res=max(res,query1(ls(x),L,R,l,mid));
	if(R>mid)
		res=max(res,query1(rs(x),L,R,mid+1,r));
	return res;
}

ll query2(ll x,ll L,ll R,ll l,ll r){
	if(L<=l&&R>=r)
		return t2[x];
	ll res=INF;
    ll mid=(l+r)>>1;
	if(L<=mid)
		res=min(res,query2(ls(x),L,R,l,mid));
	if(R>mid)
		res=min(res,query2(rs(x),L,R,mid+1,r));
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		build1(1,1,n);
		build2(1,1,n);
		while(m--){
			ll x,y;
			cin>>x>>y;
			if(x>y)
				swap(x,y);
			ll l=x+1,r=y-1;
			if(l<=r){
				ll mn=query2(1,l,r,1,n);
				ll mx=query1(1,l,r,1,n);
				if(mn<x||mx>y){
					cout<<"No\n";
				}
				else{
					cout<<"Yes\n";
					update(1,x,1,n,y);
					update(1,y,1,n,x);
				}
			}
			else{
				cout<<"Yes\n";
				update(1,x,1,n,y);
				update(1,y,1,n,x);
			}
		}
	}
	return 0;
}