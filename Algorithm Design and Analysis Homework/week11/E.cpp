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
//题解：枚举八个位置的排列，计算每种排列下的价值，取最大值
int T=1;
ll a[10];

ll cal(){
	ll res=0;
	for(int i=0;i<8;i++){
		if(i==1)
			res+=a[0]*a[1];
		else if(i==7)
			res+=a[7]*a[6];
		else
			res+=a[i]*a[i-1]*a[i+1];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]){
		sort(a,a+8);
		ll ans=0;
		do{
			ll v=cal();
			ans=max(ans,v);
		}while(next_permutation(a,a+8));
		cout<<ans<<'\n';
	}
	return 0;
}