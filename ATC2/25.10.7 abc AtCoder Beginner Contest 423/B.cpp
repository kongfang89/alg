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
const int MAX_N = 110;

int T=1;
int n,l[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
		int first=0,second=0;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			if(l[i]&&!first)
				first=i;
			if(l[i])
				second=i;
		}
		cout<<second-first<<'\n';
	}
	return 0;
}