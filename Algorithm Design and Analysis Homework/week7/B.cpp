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
//题解：dfs搜索，从第一个位置开始，枚举每一类数字，然后递归搜索下一个位置，直到所有位置都填满，输出结果
int T=1;
int n,a[MAX_N],vis[MAX_N],cnt[MAX_N],tot,ans[MAX_N];

void dfs(int now){
    if(now==n){
        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i=0;i<tot;i++){
        if(cnt[i]==0)
            continue;
        cnt[i]--;
        ans[now]=a[i];
        dfs(now+1);
        cnt[i]++;
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        tot=0;
        for(int i=0;i<n;i++){
            if(tot==0||a[tot-1]!=a[i])
                a[tot++]=a[i];
            cnt[tot-1]++;
        }
        dfs(0);
	}
	return 0;
}