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
/*题解：
区间dp问题，dp[l][r]表示当前决策者可以拿到的最高分数
由于取法对分数没有加成，所以对于当前情况，两人可以取得的总分是不会变的
对当前决策者而言，他的目标就是让自己的得分和对方的得分的差最大
所以在dp过程中我们可以记录当前括号串的总分值
那我们可以设想三种情况：
取s[l]，我的得分就是总分-对方在s[l+1]到s[r]的最高得分
取s[r]，我的得分就是总分-对方在s[l]到s[r-1]的最高得分
取s[l]和s[r]，我的得分就是总分-对方在s[l+1]到s[r-1]的最高得分
小明先手，故小明的最高分数就是dp[0][n-1]，小红的最高分数就是总分-dp[0][n-1]，比较两者大小即可判断胜负
*/
int T=1;
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
    // cin>>T;
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