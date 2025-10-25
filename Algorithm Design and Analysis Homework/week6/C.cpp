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
//题解：贪心，结束时间早的先安排，因为结束时间早则剩下时间多
int T=1;
int n;
struct node{
	int s,t;
}a[MAX_N];

int cmp(node x,node y){
	return x.t<y.t;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>a[i].s>>a[i].t;
		sort(a+1,a+n+1,cmp);
		int now=0,ans=0;
		for(int i=1;i<=n;i++){
			if(a[i].s>=now){
				ans++;
				now=a[i].t;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}