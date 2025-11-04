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
int n,vis[MAX_N],p[MAX_N];
double a[MAX_N],x[MAX_N],ans;

double getx(int now,double r){
    double tx=r;
    for(int i=0;i<now;i++)
        tx=max(tx,x[i]+sqrt((a[p[i]]+r)*(a[p[i]]+r)-(a[p[i]]-r)*(a[p[i]]-r)));
    return tx;
}

void dfs(int now,double val){
    if(now==n){
        ans=min(ans,val);
        return;
    }
    double mi=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        if(vis[i])
            continue;
        mi=min(mi,a[i]);
    }
    double res=max(val,getx(now,mi)+mi*((n-now)*2-1));
    if(res>=ans)
        return;
    for(int i=0;i<n;i++){
        if(vis[i])
            continue;
        p[now]=i;
        x[now]=getx(now,a[i]);
        vis[i]=1;
        dfs(now+1,max(val,x[now]+a[i]));
        vis[i]=0;
    }
}

int main(){
	while(scanf("%d",&n)!=EOF){
        memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
            scanf("%lf",&a[i]);
        ans=0x3f3f3f3f;
        dfs(0,0);
        printf("%.7f\n",ans);
	}
	return 0;
}