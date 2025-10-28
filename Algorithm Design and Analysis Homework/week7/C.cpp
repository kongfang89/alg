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
int n,r,a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>r){
		for(int i=0;i<n;i++)
			cin>>a[i];
		int m=1<<n;
		for(int i=0;i<m;i++){
			if(__builtin_popcount(i)!=r)
				continue;
			for(int j=0;j<n;j++){
				if(i&(1<<j))
					cout<<a[j]<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}