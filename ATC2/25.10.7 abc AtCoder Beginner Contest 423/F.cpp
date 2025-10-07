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
const int MAX_N = 21;

int T=1;
int n,m;
ll y,ans,a[MAX_N],s[MAX_N],C[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
    for(int i=0;i<MAX_N;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
        }
    }
	while(T--){
        cin>>n>>m>>y;
		for(int i=0;i<n;i++)
            cin>>a[i];
        for(int S=0;S<(1<<n);S++){
            int cnt=0;
            __int128 lcm=1;
            for(int i=0;i<n;i++){
                if((S>>i)&1){
                    cnt++;
                    if(lcm>y)
                        continue;
                    lcm=lcm/__gcd(lcm,(__int128)a[i])*a[i];
                }
            }
            s[cnt]+=y/lcm;
        }
        for(int i=m;i<=n;i++){
            if((i-m)&1)
                ans-=C[i][m]*s[i];
            else
                ans+=C[i][m]*s[i];
        }
        cout<<ans<<'\n';
	}
	return 0;
}