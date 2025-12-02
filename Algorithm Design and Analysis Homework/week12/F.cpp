#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"true"<<endl
#define NO cout<<"false"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1;

int T=1;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		string s;
        cin>>s;
        int n=s.size();
        int flag=1;
        int id;
        for(int i=0;i<n;i++){
            if(s[i]==s[n-i-1])
                continue;
            else{
                flag=0;
                id=i;
                break;
            }
        }
        if(flag){
            YES;
            continue;
        }
        string t=s.substr(id,n-2*id-1);
        string r=t;
        reverse(r.begin(),r.end());
        if(t==r){
            YES;
            continue;
        }
        t=s.substr(id+1,n-id*2-1);
        r=t;
        reverse(r.begin(),r.end());
        if(t==r){
            YES;
            continue;
        }
        NO;
    }
    return 0;
}