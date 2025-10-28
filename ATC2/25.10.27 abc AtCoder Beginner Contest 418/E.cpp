#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 2010;

int T=1;
ll n,x[MAX_N],y[MAX_N],ans,px;

unordered_map<ld,ll> K;
unordered_map<ld,unordered_map<ld,ll>> D;

ld dis(int i,int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

void solve(int i,int j){
    ld k=100000000;
    if(y[i]!=y[j])
        k=(ld)(x[i]-x[j])/(y[i]-y[j]);
    ans+=K[k];
    K[k]++;
    ld d=dis(i,j);
    px+=D[k][d];
    D[k][d]++;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>x[i]>>y[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                solve(i,j);
            }
        }
        ans-=px/2;
        cout<<ans<<'\n';
	}
	return 0;
}