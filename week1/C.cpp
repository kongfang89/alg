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
int n;
int a[MAX_N],b[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
		int ma=0,mb=1001;
		for(int i=0;i<n;i++){
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
			mb=min(mb,b[i]);
		}
		if(ma>mb)
			cout<<0<<endl;
		else
			cout<<mb-ma+1<<endl;
	}
	return 0;
}