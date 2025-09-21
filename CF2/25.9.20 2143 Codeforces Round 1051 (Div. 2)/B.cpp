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

int T=1;
int n,k;
int a[MAX_N],b[MAX_N];

int cmp(int x,int y){
	return x>y;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<k;i++)
			cin>>b[i];
		sort(a,a+n,cmp);
		sort(b,b+k);
		int now=0;
		for(int i=0;i<k;i++){
			if(now+b[i]-1<n){
				a[now+b[i]-1]=0;
				now+=b[i];
			}
			else
				break;
		}
		ll ans=0;
		for(int i=0;i<n;i++)
			ans+=a[i];
		cout<<ans<<'\n';
	}
	return 0;
}