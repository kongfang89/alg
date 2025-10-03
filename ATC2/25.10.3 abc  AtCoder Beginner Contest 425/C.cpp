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
		int n,q;
        cin>>n>>q;
        vector<ll> a(2*n+1),s(2*n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i+n]=a[i];
        }
        s[0]=0;
        for(int i=1;i<=2*n;i++)
            s[i]=s[i-1]+a[i];
        int start=1,end=n;
        while(q--){
            int t;
            cin>>t;
            if(t==1){
                int c;
                cin>>c;
                start+=c;
                if(start>n)
                    start-=n;
                end+=c;
                if(end>n)
                    end-=n;
            }
            else{
                int l,r;
                cin>>l>>r;
                cout<<s[start+r-1]-s[start+l-1-1]<<'\n';
            }
        }
	}
	return 0;
}