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
int na,nb,nc;
int check(int x){
    if(na-x>=0&&nc-x>=0&&na+nc+nb-3*x>=0)
        return 1;
    return 0;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
        cin>>na>>nb>>nc;
        int l=0,r=max(na,nc)+1;
        while(l+1!=r){
            int mid=l+r>>1;
            if(check(mid))
                l=mid;
            else
                r=mid;
        }
        cout<<l<<'\n';
	}
	return 0;
}