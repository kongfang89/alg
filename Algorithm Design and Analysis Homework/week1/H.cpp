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
//题解：看注释
int T=1;
int n,q;
int a[MAX_N];
//dp[i]表示按长度i分组的答案
//last[i]表示元素i上次出现的位置
//d[i]表示每个数相邻两次出现的距离为i的次数
//s[i]表示每个数相邻两次出现的距离>=i的次数
int dp[MAX_N],last[MAX_N],d[MAX_N],s[MAX_N];

int main(){
    // ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    // cin>>T;
	while(scanf("%d %d",&n,&q)!=EOF){
        //初始化
        memset(last,-1,sizeof(last));
        for(int i=0;i<=n;i++)
            d[i]=0;
		dp[1]=n;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            //统计每个元素与上次出现位置距离的次数，首次出现则距离为i+1
            d[i-last[a[i]]]++;
            //更新上次出现位置
            last[a[i]]=i;
        }
        //后缀和 s[i]=d[i]+d[i+1]+...+d[n-1]
        for(int i=0;i<=n;i++)
            s[i]=d[i];
		for(int i=n-1;i>=1;i--)
            s[i]+=s[i+1];
        //分组长度每+1就要少一组，记录少的这一组的答案
        int t=0;
        //dp
        for(int i=2;i<=n;i++){
            //如果按长度i分组，最后一组的第一个数是最后一组新出现的，则要多-1
            if(last[a[n-i+1]]==n-i+1)
                t++;
            //按长度i分组的答案=(按长度i-1分组的答案)+(每个数相邻两次出现的距离>=i的次数)-(按长度i-1分组的最后一组的答案)
            dp[i]=dp[i-1]+s[i]-t;
        }
        //查询
		while(q--){
			int w;
			scanf("%d",&w);
			printf("%d\n",dp[w]);
		}
	}
	return 0;
}