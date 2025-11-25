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
const int MAX_N = 1010;

int T=1;
int n,m,a[MAX_N];
int dp[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
        if(n==0)
            break;
		memset(dp,0,sizeof(dp));
        int ma=-0x3f3f3f3f;
        int id=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>ma){
                id=i;
                ma=a[i];
            }
        }
        cin>>m;
        if(m<5){
            cout<<m<<'\n';
            continue;
        }
        m-=5;
        for(int i=0;i<n;i++){
            if(i==id)
                continue;
            for(int j=m;j>=a[i];j--)
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
        cout<<m+5-dp[m]-a[id]<<'\n';
	}
	return 0;
}