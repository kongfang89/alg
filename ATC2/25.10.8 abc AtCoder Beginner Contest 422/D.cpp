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
int n,k;

void split(int now,int sum){
	if(now==n){
		cout<<sum<<' ';
		return;
	}
	split(now+1,sum/2);
	split(now+1,sum/2+sum%2);
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>k;
		if(k%(1<<n)==0){
			cout<<0<<'\n';
			for(int i=0;i<(1<<n);i++)
				cout<<k/(1<<n)<<' ';
			cout<<'\n';
		}
		else{
			cout<<1<<'\n';
			split(0,k);
			cout<<'\n';
		}
	}
	return 0;
}