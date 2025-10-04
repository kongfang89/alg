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
const int MAX_N = 4e5+10;

int T=1;
int n;
int a[MAX_N],b[MAX_N],vis[MAX_N];
vector<int> G[MAX_N];
int ans;

void dfs(int u){
    if(vis[u])
        return;
    vis[u]=1;
    ans++;
    for(auto v:G[u]){
        dfs(v);
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        vector<int> v;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i];
            if(a[i]+b[i]==0){
                v.push_back(i);
            }
            else{
                G[a[i]].push_back(i);
                G[b[i]].push_back(i);
            }
        }
        for(auto x:v)
            dfs(x);
        cout<<ans<<'\n';
	}
	return 0;
}