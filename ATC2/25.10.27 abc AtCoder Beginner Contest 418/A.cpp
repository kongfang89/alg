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
int n;
string s;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>s;
        if(n<3){
            NO;
            continue;
        }
        s=s.substr(n-3,3);
        if(s=="tea")
            YES;
        else
            NO;
	}
	return 0;
}