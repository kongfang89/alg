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
/*题解：
dp[i][j]=max{dp[i-1][j],dp[i][j-w[i]]+v[i]}表示对于考虑前i个物品，容量为j的背包，最大价值。
要么从前i-1个物品中继承下来，要么选择第i个物品（可以多次选择），则剩余容量为j-w[i]，加上v[i]。
*/
int T=1;
int n,b;
int w[MAX_N],v[MAX_N];
int dp[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>b){
		for(int i=1;i<=n;i++)
			cin>>w[i]>>v[i];
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=w[i];j<=b;j++)
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		cout<<dp[b]<<'\n';
	}
	return 0;
}