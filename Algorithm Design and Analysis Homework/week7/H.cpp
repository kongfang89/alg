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
const int MAX_N = 100;
/*题解：
统计总长，最差情况就是全部拼成一根；然后从大到小排序，因为先用大的肯定更好拼；记录每个长度相同的木棒的最后位置，如果这根拼不出来，等长的也拼不出来；
枚举总长的因数，不是因数也拼不出来；dfs搜索，从第一根木棒开始，如果这根拼完了，且是最后一根就结束，不是就找当前可用的最大木棒继续拼；
如果这根没拼完，二分找当前可用的最大木棒，从这根开始一根根尝试继续拼；
如果当前剩下的长度和用的木棒长度相等，继续拼却失败了，说明不用继续了，因为用小的肯定不如用大的好拼；
如果当前剩下的长度等于要拼的长度，说明新的要拼的还没拼，继续拼却失败了，说明这根木棒完全用不了，那也不用继续了
*/
int T=1;
int n,m,len,a[MAX_N],sum,nxt[MAX_N],vis[MAX_N],flag;

int cmp(int a,int b){
    return a>b;
}

void dfs(int now,int last,int rest){
    int i;
    if(rest==0){
        if(now==m){
            flag=1;
            return;
        }
        for(i=1;i<=n;i++)
            if(vis[i]==0)
                break;
        vis[i]=1;
        dfs(now+1,i,len-a[i]);
        vis[i]=0;
        if(flag)
            return;
    }
    int l=last+1,r=n;
    while(l<r){
        int mid=l+r>>1;
        if(a[mid]<=rest)
            r=mid;
        else
            l=mid+1;
    }
    for(i=l;i<=n;i++){
        if(vis[i])
            continue;
        vis[i]=1;
        dfs(now,i,rest-a[i]);
        vis[i]=0;
        if(flag)
            return;
        if(rest==a[i]||rest==len)
            return;
        i=nxt[i];
        if(i==n)
            return;
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a+1,a+n+1,cmp);
        for(int i=n;i>=1;i--){
            if(a[i]==a[i+1])
                nxt[i]=nxt[i+1];
            else
                nxt[i]=i;
        }
        for(len=a[1];len<=sum/2;len++){
            if(sum%len!=0)
                continue;
            m=sum/len;
            flag=0;
            vis[1]=1;
            dfs(1,1,len-a[1]);
            vis[1]=0;
            if(flag){
                cout<<len<<'\n';
                return 0;
            }
        }
        cout<<sum<<'\n';
	}
	return 0;
}