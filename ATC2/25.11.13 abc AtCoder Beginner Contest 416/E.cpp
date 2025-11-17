#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 510;

int T=1;
int n,m,q,k,ap[MAX_N],vis[MAX_N];
ll t,d[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		memset(d,0x3f,sizeof(d));
		for(int i=1;i<=n;i++) d[i][i]=0;
		for(int i=1;i<=m;i++){
			int u,v;
			ll w;
			cin>>u>>v>>w;
			d[u][v]=min(d[u][v],w);
			d[v][u]=min(d[v][u],w);
		}
		cin>>k>>t;
		for(int i=1;i<=k;i++){
			cin>>ap[i];
			vis[ap[i]]=1;
		}
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				d[ap[i]][ap[j]]=min(d[ap[i]][ap[j]],t);
		for(int kk=1;kk<=n;kk++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					d[i][j]=min(d[i][j],d[i][kk]+d[kk][j]);
		cin>>q;
		while(q--){
			int op;
			cin>>op;
			if(op==1){
				int u,v;
				ll w;
				cin>>u>>v>>w;
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						d[i][j]=min(d[i][j],d[i][u]+w+d[v][j]);
						d[i][j]=min(d[i][j],d[i][v]+w+d[u][j]);
					}
				}
			}
			else if(op==2){
				int u;
				cin>>u;
				if(vis[u])
					continue;
				vis[u]=1;
				ap[++k]=u;
				for(int i=1;i<=k;i++){
					d[ap[i]][u]=min(d[ap[i]][u],t);
					d[u][ap[i]]=min(d[u][ap[i]],t);
				}
				for(int i=1;i<=n;i++){
					ll mi=INF;
					for(int j=1;j<k;j++)
						mi=min(mi,d[ap[j]][i]);
					for(int j=1;j<=n;j++)
						d[j][i]=min(d[j][i],d[j][u]+t+mi);
					mi=INF;
					for(int j=1;j<k;j++)
						mi=min(mi,d[i][ap[j]]);
					for(int j=1;j<=n;j++)
						d[i][j]=min(d[i][j],mi+t+d[u][j]);
				}
			}
			else{
				ll ans=0;
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++)
						if(d[i][j]<INF)
							ans+=d[i][j];
				cout<<ans<<'\n';
			}
		}
	}
	return 0;
}