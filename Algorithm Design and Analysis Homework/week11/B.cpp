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
const int MAX_N = 1;

int T=1;
int n,m;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>m){
        int l=1,r=n;
        int ans=n;
        for(int i=1;i<=m;i++){
            int x;
            cin>>x;
            int cnt=r-l+1;
            int half=cnt/2;
            if(x==0){
                r=l+half-1;
                ans=r;
            }
            else if(x==1){
                l=l+half;
                r=l+half-1;
                ans=r;
            }
            else{
                ans=r;
                break;
            }
        }
        cout<<ans<<'\n';
	}
	return 0;
}