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
const int MAX_N = 100;
//题解：dp[i][0]表示从第i块馅饼开始轮到Bob先手时Bob能获得的最大分数，dp[i][1]表示从第i块馅饼开始轮到Alice先手时Bob能获得的最大分数
int T=1;
int n;
int a[MAX_N];
int dp[MAX_N][2];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        dp[n][0]=a[n];
        dp[n][1]=0;
        for(int i=n-1;i>=1;i--){
            int res1=a[i]+dp[i+1][1];
            int res2=dp[i+1][0];
            dp[i][0]=max(res1,res2);
            dp[i][1]=min(res1,res2);
        }
        cout<<sum-dp[1][0]<<' '<<dp[1][0]<<'\n';
	}
	return 0;
}