#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 2e5+10;

int T=1;
int n,q;
int f[MAX_N],s[MAX_N],c[MAX_N];

int find(int x){
    if(f[x]==x)
        return x;
    return f[x]=find(f[x]);
}

void unite(int x,int y){
	int f1=find(x),f2=find(y);
	f[f2]=f1;
}


int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>q;
        for(int i=1;i<=n;i++)
            f[i]=i;
        for(int i=0;i<q;i++){
            int t;
            cin>>t;
            if(t==1){
                int u,v;
                cin>>u>>v;
                u=find(u);
                v=find(v);
                if(u!=v){
                    unite(u,v);
                    s[u]+=s[v];
                }
            }
            else if(t==2){
                int u;
                cin>>u;
                s[find(u)]-=c[u];
                c[u]^=1;
                s[find(u)]+=c[u];
            }
            else{
                int u;
                cin>>u;
                if(s[find(u)])
                    YES;
                else
                    NO;
            }
        }
	}
	return 0;
}