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
const int MAX_N = 20;
//题解：先给第一个节点染色，枚举每个节点填的颜色是否会引起冲突，然后递归搜索下一个节点，统计方案数，最后乘以颜色数就是总方案数，因为颜色是对称的
int T=1;
int n,m,q,ans,color[MAX_N];
vector<int> G[MAX_N];

int check(int now,int c){
	for(auto v:G[now])
        if(color[v]==c)
            return 0;
    return 1;
}

void dfs(int now){
	if(now==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=m;i++){
		if(!check(now,i))
			continue;
		color[now]=i;
		dfs(now+1);
		color[now]=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>m>>q){
        for(int i=1;i<=n;i++)
            G[i].clear();
        memset(color,0,sizeof(color));
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
        ans=0;
        color[1]=1;
		dfs(2);
		ans*=m;
		cout<<ans<<'\n';
	}
	return 0;
}