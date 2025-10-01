#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 100003;
//const int mod = 998244353;
const int MAX_N = 1e6+10;
//题解：枚举每一级台阶，对于第i级台阶，ans[i]=ans[i-k]+ans[i-k+1]+...+ans[i-1]
int T=1;
int n,k;
int ans[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>k){
		ans[0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(i-j>=0){
					ans[i]+=ans[i-j];
					ans[i]%=mod;
				}
			}
		}
		cout<<ans[n]<<endl;
	}
	return 0;
}