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
const int MAX_N = 310;

int T=1;
int n;
struct node
{
	int x,y,z;
};
vector<node> v;
int M[MAX_N][MAX_N];
int dp[MAX_N];

int dfs(int u){
	if(dp[u]!=-1)
		return dp[u];
	dp[u]=v[u].z;
	for(int i=0;i<n;i++){
		if(!M[u][i])
			continue;
		dp[u]=max(dp[u],dfs(i)+v[u].z);
	}
	return dp[u];
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		v.clear();
		for(int i=0;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			v.push_back({max(x,y),min(x,y),z});
			v.push_back({max(y,z),min(y,z),x});
			v.push_back({max(z,x),min(z,x),y});
		}
		n*=3;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				M[i][j]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(v[i].x>v[j].x&&v[i].y>v[j].y)
					M[i][j]=1;
		int ans=0;
		for(int i=0;i<n;i++)
			dp[i]=-1;
		for(int i=0;i<n;i++)
			ans=max(ans,dfs(i));
		cout<<ans<<'\n';
	}
	return 0;
}