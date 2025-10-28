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
string s;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>s){
        int ans=0;
        int n=1<<8;
        for(int i=0;i<n;i++){
            int res=(i>>7)&1;
            for(int j=0;j<7;j++){
                if(s[j]=='+')
                    res+=((i>>j)&1);
                else
                    res-=((i>>j)&1);
            }
            if(res>0)
                ans++;
        }
		cout<<ans<<'\n';
	}
	return 0;
}