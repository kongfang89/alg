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

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    // cin>>T;
	while(T--){
        //对于n=101010B，满足2^k<=n条件最大的2^k为100000B，注意到n与2^k位数相同，故答案为n的位数
        ll n;
        cin>>n;
        int cnt=0;
        while(n!=1){
            n/=2;
            cnt++;
        }
		cout<<cnt<<endl;
	}
	return 0;
}