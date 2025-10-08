#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 5e5+10;

int T=1;
ll n,x[MAX_N],y[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=0;i<n;i++)
            cin>>x[i]>>y[i];
        mt19937_64 r(time(0));
        for(int _=0;_<100;_++){
            int i,j;
            do{
                i=r()%n,j=r()%n;
            }while(i==j);
            ll a=y[i]-y[j];
            ll b=x[j]-x[i];
            ll c=x[i]*y[j]-x[j]*y[i];
            int cnt=0;
            for(int k=0;k<n;k++)
                cnt+=a*x[k]+b*y[k]+c==0;
            if(cnt*2>n){
                YES;
                cout<<a<<' '<<b<<' '<<c<<'\n';
                return 0;
            }
        }
        NO;
	}
	return 0;
}