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
const int MAX_N = 50;
//题解：dfs搜索，从第一行开始，枚举每一行皇后的位置，访问数组0维表示列，1维2维表示左右对角线，然后递归搜索下一行，直到所有行都填满，统计方案数
int T=1;
int n,ans,vis[3][MAX_N];

void dfs(int now){
    if(now==n+1){
        ans++;
        return;
    }  
    for(int i=1;i<=n;i++){
        if(vis[0][i]||vis[1][now+i]||vis[2][now-i+n])
            continue;
        vis[0][i]=1;
        vis[1][now+i]=1;
        vis[2][now-i+n]=1;
        dfs(now+1);
        vis[0][i]=0;
        vis[1][now+i]=0;
        vis[2][now-i+n]=0;
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
        memset(vis,0,sizeof(vis));
        ans=0;
		dfs(1);
        cout<<ans<<'\n';
	}
	return 0;
}