#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N = 310;

int n,a[MAX_N];
int dp[MAX_N][MAX_N];

int main(){	
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

/*
样例

输出

*/