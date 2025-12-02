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

int T=1;
int n;
int a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];		
		int l=1; 
		int ans=0;
		int zero=0;
		for(int r=1;r<=n;r++){
			if(a[r]==0)
				zero++;
			while(zero>1){
				if(a[l]==0)
					zero--;
				l++;
			}
			ans=max(ans,r-l);
		}
		cout<<ans<<endl;
	}
	return 0;
}