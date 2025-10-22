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

int T=1;
int n,a[MAX_N],s[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;i++)
            cin>>a[i];
        int cnt=0;
        s[++cnt]=a[1];
        for(int i=2;i<=n;i++){
            if(s[cnt]<a[i])
                s[++cnt]=a[i];
            else{
                int p=lower_bound(s+1,s+cnt+1,a[i])-s;
                s[p]=a[i];
                for(int j=1;j<=cnt;j++)
                    cout<<s[j]<<" ";
                cout<<endl;
            }
        }
        cout<<cnt<<'\n';
	}
	return 0;
}