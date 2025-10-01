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

string s;
int dp[MAX_N][MAX_N];
map<char,int> mp;

int dfs(int l,int r,int su){
    if(l>r)
        return dp[l][r]=0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(l==r)
        return dp[l][r]=mp[s[l]];
    int &res=dp[l][r];
    res=0;
    dp[l][r]=max(dp[l][r],su-dfs(l+1,r,su-mp[s[l]]));
    dp[l][r]=max(dp[l][r],su-dfs(l,r-1,su-mp[s[r]]));
    if((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']')||(s[l]=='{'&&s[r]=='}'))
        dp[l][r]=max(dp[l][r],su-dfs(l+1,r-1,su-mp[s[l]]-mp[s[r]]));
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    mp['(']=1;mp[')']=1;
    mp['[']=2;mp[']']=2;
    mp['{']=3;mp['}']=3;
	while(cin>>s){
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int su=0;
		for(int i=0;i<n;i++)
            su+=mp[s[i]];
        int ming=dfs(0,n-1,su);
        if(ming>su-ming)
            cout<<"Xiao Ming Win\n";
        else if(ming<su-ming)
            cout<<"Xiao Hong Win\n";
        else
            cout<<"Draw\n";
	}
	return 0;
}