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
//题解：枚举子集，如果剩下的点都加上也不可能优于当前答案就剪枝，否则尝试加入当前点或者不加入当前点
int T=1;
int n,m,M[MAX_N][MAX_N],vis[MAX_N],ans;

void dfs(int now,int cnt){
    if(now==n+1){
        ans=max(ans,cnt);
        return;
    }
    if(cnt+(n-(now-1))<=ans)
        return;
    int flag=1;
    for(int i=1;i<=n;i++)
        if(vis[i]&&!M[now][i])
            flag=0;
    if(flag){
        vis[now]=1;
        dfs(now+1,cnt+1);
    }
    vis[now]=0;
    dfs(now+1,cnt);
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            int u,v;
            cin>>u>>v;
            M[u][v]=1;
            M[v][u]=1;
        }
        ans=0;
        dfs(1,0);
        cout<<ans<<'\n';
	}
	return 0;
}