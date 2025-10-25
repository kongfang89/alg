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
const int MAX_N = 1e4+10;
//题解：贪心，小的先放
int T=1;
int n,m,a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=0;i<m;i++)
            cin>>a[i];
        sort(a,a+m);
        int ans=0;
        for(int i=0;i<m;i++){
            if(n>=a[i])
                n-=a[i],ans++;
            else
                break;
        }
        cout<<ans<<'\n';
	}
	return 0;
}