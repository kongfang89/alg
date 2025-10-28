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
const int MAX_N = 2010;

int T=1;
int n;
int x[MAX_N],y[MAX_N];

struct frac{
    int a,b;
    frac(const int &_a,const int &_b){
        int g=__gcd(_a,_b);
        a=_a/g;
        b=_b/g;
        if(b<0){
            a=-a;
            b=-b;
        }
    }
    bool operator <(const frac &x)const{
        if(a==x.a)
            return b<x.b;
        return a<x.a;
    }
    bool operator ==(const frac &x)const{
        return a==x.a && b==x.b;
    }
};

map<frac,int> k;
map<pair<int,int>,int> mid;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                k[frac{y[i]-y[j],x[i]-x[j]}]++;
                mid[{x[i]+x[j],y[i]+y[j]}]++;
            }
        }
        ll ans=0;
        for(auto [a,b]:k)
            ans+=1LL*b*(b-1)/2;
        for(auto [a,b]:mid)
            ans-=1LL*b*(b-1)/2;
        cout<<ans<<'\n';
	}
	return 0;
}