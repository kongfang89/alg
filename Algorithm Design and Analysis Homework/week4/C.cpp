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
/*题解：
把每个原始立方体看作三个立方体，也就是将输入的三条棱分别作为高视为一个新立方体
由题目条件可得对于立方体A,B一定不会有A上叠B，B上再叠A的情况，则可根据叠放关系建图，若A能叠B，则连边A->B
显然建的图是DAG，从每个点出发树上dp，记忆化搜索即可
*/
int T=1;
int n;
struct node{
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