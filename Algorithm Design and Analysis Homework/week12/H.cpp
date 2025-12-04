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
const int MAX_N = 1300010;
//题解：用map找众数及其出现次数
int T=1;
int n,a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        map<int,int>cnt;
        int ma=0,mac=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
            if(cnt[a[i]]>mac){
                mac=cnt[a[i]];
                ma=a[i];
            }
        }
        cout<<ma<<'\n'<<mac<<'\n';
	}
	return 0;
}