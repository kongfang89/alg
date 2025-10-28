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
int n,a[MAX_N],vis[MAX_N],ans[MAX_N];

void dfs(int now){
    if(now==n){
        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        if(vis[i])
            continue;
        vis[i]=1;
        ans[now]=a[i];
        dfs(now+1);
        vis[i]=0;
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        dfs(0);
	}
	return 0;
}