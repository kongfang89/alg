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
const int MAX_N = 110;
/*题解：
设di>dj，i在j前，则s+ti-di<s+ti+tj-dj，此时最大延迟为s+ti+tj-dj；
交换i和j，则s+tj-dj<s+ti+tj-di，此时最大延迟为s+ti+tj-di。
显然后者更小，因此按截止时间升序排序
*/
int T=1;
int n;
struct node{
	int t,d;
}a[MAX_N];

int cmp(node x,node y){
	return x.d<y.d;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i].t>>a[i].d;		
		sort(a+1,a+n+1,cmp);
		int now=0,ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,now+a[i].t-a[i].d);
            now+=a[i].t;
		}
		cout<<ans<<'\n';
	}
	return 0;
}