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

int T=1;
int n,t[MAX_N][MAX_N],vis[MAX_N],ans;

void dfs(int now,int val){
	if(now==n){
		ans=min(ans,val);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(now+1,val+t[now+1][i]);
		vis[i]=0;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>t[i][j];
		ans=0x3f3f3f3f;
		dfs(0,0);
		cout<<ans<<'\n';
	}
	return 0;
}