#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1;

int T=1;
int n,l,r;
string s;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>l>>r;
		cin>>s;
		for(int i=l-1;i<r;i++)
			if(s[i]=='x'){
				NO;
				return 0;
			}
		YES;
	}
	return 0;
}