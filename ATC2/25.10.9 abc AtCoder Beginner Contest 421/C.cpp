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
int n;
string s;
vector<int> va,vb;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        cin>>s;
        for(int i=0;i<n*2;i++){
            if(s[i]=='A')
                va.push_back(i);
            else
                vb.push_back(i);
        }
        ll ans1=0,ans2=0;
        for(int i=0,j=0;i<n;i++,j+=2)
            ans1+=abs(va[i]-j);
        for(int i=0,j=0;i<n;i++,j+=2)
            ans2+=abs(vb[i]-j);
        cout<<min(ans1,ans2)<<'\n';
	}
	return 0;
}