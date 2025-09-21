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
const int MAX_N = 2e5+10;

int T=1;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
        int n;
        cin>>n;
        vector<vector<int>> G(n);
        vector<int> deg(n);
        for(int i=1;i<n;i++){
            int u,v,x,y;    
            cin>>u>>v>>x>>y;
            u--;
            v--;
            if(x>y){
                G[v].push_back(u);
                deg[u]++;
            }
            else{
                G[u].push_back(v);
                deg[v]++;
            }
        }
        queue<int> q;
        vector<int> ans(n);
        int now=1;
        for(int i=0;i<n;i++)
            if(deg[i]==0)
                q.push(i);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans[u]=now++;
            for(auto v:G[u]){
                deg[v]--;
                if(!deg[v])
                    q.push(v);
            }
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
	}
	return 0;
}