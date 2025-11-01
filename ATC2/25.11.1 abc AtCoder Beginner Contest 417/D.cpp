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
const int MAX_N = 1e4+10;

int T=1;
int n,q,p[MAX_N],a[MAX_N],b[MAX_N],s[MAX_N],dp[MAX_N][1010];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++)
            cin>>p[i]>>a[i]>>b[i];
        for(int i=0;i<=1000;i++)
            dp[n+1][i]=i;
        for(int i=n;i>=1;i--){
            for(int j=0;j<=1000;j++){
                if(j>p[i])
                    dp[i][j]=dp[i+1][max(0,j-b[i])];
                else
                    dp[i][j]=dp[i+1][j+a[i]];
            }
        }
        for(int i=1;i<=n;i++)
            s[i]=s[i-1]+b[i];
        cin>>q;
        for(int i=1;i<=q;i++){
            int x;
            cin>>x;
            if(x-1000>s[n]){
                cout<<x-s[n]<<'\n';
                continue;
            }
            if(x<=1000){
                cout<<dp[1][x]<<'\n';
                continue;
            }
            int id=lower_bound(s+1,s+n+1,x-1000)-s;
            cout<<dp[id+1][x-s[id]]<<'\n';
        }
	}
	return 0;
}