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
const int MAX_N = 3e5+10;

int T=1;
ll n,m,a[MAX_N],b[MAX_N];

int cmp(int a,int b){
    return a>b;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
        ll ans=0;
		for(int i=0;i<n;i++){
            cin>>a[i];
            ans+=a[i];
        }
		for(int i=0;i<n;i++){
            cin>>b[i];
            ans+=b[i];
        }
		sort(a,a+n);
		sort(b,b+n,cmp);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n&&a[j]+b[i]<m)
                j++;
            if(j>=n)
                break;
            ans-=m;
            j++;
        }
		cout<<ans<<endl;
	}
	return 0;
}