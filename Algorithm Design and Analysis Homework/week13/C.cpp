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
const int MAX_N = 400;

int T=1;
int n,days[MAX_N];
int cost[3];
int dp[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>cost[0]>>cost[1]>>cost[2]){
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>days[i];
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		for(int i=1;i<=n;i++){
			dp[i]=min(dp[i],dp[i-1]+cost[0]);
			int j=i;
			while(j>0&&days[i]-days[j]<7)
                j--;
			dp[i]=min(dp[i],dp[j]+cost[1]);
			j=i;
			while(j>0&&days[i]-days[j]<30)
                j--;
			dp[i]=min(dp[i],dp[j]+cost[2]);
		}
		cout<<dp[n]<<endl;
	}
	return 0;
}