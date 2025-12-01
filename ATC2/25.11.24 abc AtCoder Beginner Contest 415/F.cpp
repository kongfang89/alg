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
const int MAX_N = 5e5+10;

int T=1;
int n,q;
string s;
struct node{
    int ma,l,r,cov;
    char lv,rv;
}tr[MAX_N*4];

void pushup(int root){
    tr[root].ma=max(tr[root*2].ma,tr[root*2+1].ma);
    tr[root].l=tr[root*2].l;
    tr[root].r=tr[root*2+1].r;
    tr[root].lv=tr[root*2].lv;
    tr[root].rv=tr[root*2+1].rv;
    if(tr[root*2].rv==tr[root*2+1].lv){
        tr[root].ma=max(tr[root].ma,tr[root*2].r+tr[root*2+1].l);
        if(tr[root*2].cov)
            tr[root].l+=tr[root*2+1].l;
        if(tr[root*2+1].cov)
            tr[root].r+=tr[root*2].r;
        tr[root].cov=(tr[root*2].cov&&tr[root*2+1].cov);
    }
    else{
        tr[root].cov=0;
    }
}

void build(int root,int l,int r){
    if(l==r){
        tr[root].ma=1;
        tr[root].l=1;
        tr[root].r=1;
        tr[root].cov=1;
        tr[root].lv=s[l];
        tr[root].rv=s[l];
        return;
    }
    int mid=(l+r)/2;
    build(root*2,l,mid);
    build(root*2+1,mid+1,r);
    pushup(root);
}

void update(int root,int l,int r,int pos,char c){
    if(l==r){
        tr[root].lv=c;
        tr[root].rv=c;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
        update(root*2,l,mid,pos,c);
    else
        update(root*2+1,mid+1,r,pos,c);
    pushup(root);
}

node query(int root,int l,int r,int ql,int qr){
    if(r<ql||qr<l)
        return {-1,0,0,0,'.','.'};
    if(ql<=l&&r<=qr)
        return tr[root];
    int mid=(l+r)/2;
    node res1=query(root*2,l,mid,ql,qr);
    node res2=query(root*2+1,mid+1,r,ql,qr);
    if(res1.ma==-1)
        return res2;
    if(res2.ma==-1)
        return res1;
    node res;
    res.ma=max(res1.ma,res2.ma);
    res.l=res1.l;
    res.r=res2.r;
    res.lv=res1.lv;
    res.rv=res2.rv;
    if(res1.rv==res2.lv){
        res.ma=max(res.ma,res1.r+res2.l);
        if(res1.cov)
            res.l+=res2.l;
        if(res2.cov)
            res.r+=res1.r;
        res.cov=(res1.cov&&res2.cov);
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>q;
        cin>>s;
        s=" "+s;
        build(1,1,n);
        while(q--){
            int op;
            cin>>op;
            if(op==1){
                int id;
                char x;
                cin>>id>>x;
                update(1,1,n,id,x);
            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<query(1,1,n,l,r).ma<<'\n';
            }
        }
	}
	return 0;
}