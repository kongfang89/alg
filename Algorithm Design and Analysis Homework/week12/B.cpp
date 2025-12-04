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
const int MAX_N = 1e5+10;
/*题解：使用分治优化动态规划
dp[t][i] = min over j < i ( dp[t-1][j] + cost(j+1, i) )
*/
int T=1;
int n,k;
int a[MAX_N];
ll dp[21][MAX_N];
ll cnt[MAX_N];
ll cost=0;
int curl=1,curr=0;

void add(int x) {
    cost+=cnt[x];
    cnt[x]++;
}

void remov(int x) {
    cnt[x]--;
    cost-=cnt[x];
}

void change(int l,int r){
    while(curl>l)
        add(a[--curl]);
    while(curr<r)
        add(a[++curr]);
    while(curl<l)
        remov(a[curl++]);
    while(curr>r)
        remov(a[curr--]);
}

void solve(int t,int L,int R,int l,int r){
    if(L>R)
        return;
    int mid=L+R>>1;
    ll mi=1e18;
    int id=-1;
    int start=min(mid-1,r);
    for(int j=l;j<=start;j++){
        change(j+1,mid);
        ll val=dp[t-1][j]+cost;
        if(val<mi){
            mi=val;
            id=j;
        }
    }
    dp[t][mid]=mi;
    solve(t,L,mid-1,l,id);
    solve(t,mid+1,R,id,r);
}

int main(){
    ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    // cin>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=0;i<=k;i++)
            for(int j=0;j<=n;j++)
                dp[i][j]=1e18;
        dp[0][0]=0;
        for(int i=1;i<=k;i++){
            memset(cnt,0,sizeof(cnt));
            curl=1;
            curr=0;
            cost=0;
            solve(i,1,n,0,n-1);
        }
        cout<<dp[k][n]<<'\n';
    }
    return 0;
}
