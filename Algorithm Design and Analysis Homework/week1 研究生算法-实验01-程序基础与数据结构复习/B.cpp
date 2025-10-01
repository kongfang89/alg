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
const int MAX_N = 2e5+10;
//题解：把%200余数相同的数分为一组，对这200组分别计算每组能凑多少对，累加即为答案
int T=1;
int n;
int a[MAX_N];
int cnt[200];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
			cnt[a[i]%200]++;
		}
		int ans=0;
		for(int i=0;i<200;i++){
			if(cnt[i]){
				//n个数两两配对，不考虑次序的配对数为n*(n-1)/2
				ans+=(cnt[i])*(cnt[i]-1)/2;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}