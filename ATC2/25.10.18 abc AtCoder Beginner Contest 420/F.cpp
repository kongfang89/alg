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
const int MAX_N = 5e5+10;

int T=1;
int n,m,k;
vector<int> a[MAX_N];
int h[MAX_N],r[MAX_N];
vector<ll> dp[MAX_N];
stack<int> s;
ll ans=0;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            a[i].resize(m+5);
            dp[i].resize(m+5);
            for(int j=1;j<=m;j++){
                char c;
                cin>>c;
                if(c=='.')
                    a[i][j]=0;
                else
                    a[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==0)
                    h[j]++;
                else
                    h[j]=0;
            }
            for(int j=m;j>=1;j--){
                while(!s.empty()&&h[s.top()]>h[j])
                    s.pop();
                r[j]=s.empty()?m+1:s.top();
                s.push(j);
            }
            while(!s.empty())
                s.pop();
            for(int j=1;j<=m;j++){
                while(!s.empty()&&h[s.top()]>=h[j])
                    s.pop();
                int l=s.empty()?0:s.top();
                if(h[j]){
                    int x=j-l,y=r[j]-j;
                    if(x>y)
                        swap(x,y);
                    dp[h[j]][1]++;
                    dp[h[j]][x+1]--;
                    dp[h[j]][y+1]--;
                    dp[h[j]][x+y+1]++;
                }
                s.push(j);
            }
            while(!s.empty())
                s.pop();
        }
        for(int i=n;i>=1;i--){
            for(int j=1;j<=m;j++)
                dp[i][j]+=dp[i][j-1];
            for(int j=1;j<=m;j++)
                dp[i][j]+=dp[i][j-1];
            for(int j=1;j<=m;j++){
                if(i!=n)
                    dp[i][j]+=dp[i+1][j];
                if(i*j<=k)
                    ans+=dp[i][j];
            }
        }
        cout<<ans<<'\n';
	}
	return 0;
}