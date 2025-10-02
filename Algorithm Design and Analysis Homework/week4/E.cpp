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
const int MAX_N = 110;

int n;
string s;
int dp[MAX_N][MAX_N];

int dfs(int l,int r){
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l==r)
		return dp[l][r]=1;
	if(l>r)
		return dp[l][r]=0;
	dp[l][r]=INT_MAX;
	for(int i=l;i<r;i++)
		dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i+1,r));
	if((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']')||(s[l]=='{'&&s[r]=='}'))
		dp[l][r]=min(dp[l][r],dfs(l+1,r-1));
	return dp[l][r];
}

int main(){	
	while(cin>>s){
		n=s.size();
		memset(dp,-1,sizeof(dp));
		int ans=dfs(0,n-1);
		if(ans)
			cout<<ans<<'\n';
		else
			cout<<"SZTU_WOD YYDS!\n";
	}	
	return 0;
}