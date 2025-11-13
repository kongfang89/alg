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
	while(T--){
		cin>>s;
        int last=-1;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;){
            if(s[i]=='#'){
                if(last!=-1){
                    s[last]='o';
                    last=-1;
                }
                while(s[i]=='#')
                    i++;
            }
            else{
                last=i;
                i++;
            }
        }
        if(s[n-1]!='#')
            s[n-1]='o';
        cout<<s<<'\n';
	}
	return 0;
}