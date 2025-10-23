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
int n,m;
string s,t;
int d[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		cin>>s>>t;
		for(int i=1;i<=m;i++){
			int l,r;
			cin>>l>>r;
			d[l]++;
			d[r+1]--;
		}
		for(int i=1;i<=n;i++)
			d[i]+=d[i-1];
		for(int i=1;i<=n;i++){
			if(d[i]%2==1)
				cout<<t[i-1];
			else
				cout<<s[i-1];
		}
		cout<<'\n';
	}
	return 0;
}