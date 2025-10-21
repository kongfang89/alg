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
const int MAX_N = 1e6+10;
/*题解：
tail[i]表示长度为i的上升子序列的最小末尾元素
使用贪心+二分查找优化
*/
int T=1;
int n,b;
int a[MAX_N];
int tail[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>b){
		a[1]=b;
		for(int i=2;i<=n;i++)
			a[i]=1LL*(a[i-1]+1)*(a[i-1]+1)%mod;
		int len=0;
		for(int i=1;i<=n;i++){
			if(len==0||a[i]>tail[len])
				tail[++len]=a[i];
			else{
				int pos=lower_bound(tail+1,tail+1+len,a[i])-tail;
				tail[pos]=a[i];
			}
		}
		cout<<len<<'\n';
	}
	return 0;
}