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
int n,m;
int a[MAX_N];
map<int,int> mp;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(mp[x]>0)
                mp[x]--;
        }
        for(auto [x,y]:mp){
            if(y>0){
                for(int i=0;i<y;i++)
                    cout<<x<<" ";
            }
        }
        cout<<'\n';
	}
	return 0;
}