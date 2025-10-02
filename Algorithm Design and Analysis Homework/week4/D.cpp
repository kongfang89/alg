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
const int MAX_N = 310;
/*题解：
区间dp问题，dp[i][j]表示从第i个矩阵乘到第j个矩阵的最少元素相乘次数
a*b的矩阵与b*c的矩阵相乘，元素相乘次数为a*b*c
则枚举i到j之间的每个k，dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j])
*/
int T=1;
int n,a[MAX_N];
int dp[MAX_N][MAX_N];

int main(){	
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		memset(dp,0x7f,sizeof(dp));
		for(int i=0;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			dp[i][i]=0;
		for(int len=2;len<=n;len++)
			for(int i=1;i<=n-len+1;i++){
				int j=i+len-1;
				for(int k=i;k<j;k++)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
			}
		cout<<dp[1][n]<<'\n';
	}	
	return 0;
}