#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 510;

int T=1;
int n,m;
ll seed1,seed2,mod,base;

struct BIT{
    ll s[MAX_N][MAX_N];
    void update(int x,int y,ll val){
        if(!x||!y)
            return;
        for(int i=x;i<=n;i+=i&-i)
            for(int j=y;j<=n;j+=j&-j)
                s[i][j]+=val;
    }
    ll query(int x,int y){
        ll ret=0;
        for(int i=x;i;i-=i&-i)
            for(int j=y;j;j-=j&-j)
                ret+=s[i][j];
        return ret;
    }
}A,B,C,D;

void add(int x,int y,ll val){
    A.update(x,y,val*x*y),B.update(x,y,val*x),C.update(x,y,val*y),D.update(x,y,val);
}

ll query(int x,int y){
    return A.query(x,y)+y*(B.query(x,n)-B.query(x,y))+x*(C.query(n,y)-C.query(x,y))+x*y*(D.query(n,n)-D.query(x,n)-D.query(n,y)+D.query(x,y));
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        cin>>seed1>>seed2>>mod>>base;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                int x1,y1,x2,y2;
                ll v;
                x1=i,y1=j,x2=i,y2=j;
                v=(i*seed1+j*seed2)%mod+base;
                add(x1,y1,v),add(x1,y2+1,-v),add(x2+1,y1,-v),add(x2+1,y2+1,v);
            }
        while(m--){
            int op;
            cin>>op;
            if(op==1){
                int x1,y1,x2,y2,v;
                cin>>x1>>y1>>x2>>y2>>v;
                add(x1,y1,v),add(x1,y2+1,-v),add(x2+1,y1,-v),add(x2+1,y2+1,v);
            }
            else{
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                cout<<query(x1,y1)-query(x1,y2+1)-query(x2+1,y1)+query(x2+1,y2+1)<<'\n';
            }
        }
	}
	return 0;
}