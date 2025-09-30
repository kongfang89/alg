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
const int MAX_N = 40;

int T=1;
int n;
int ans[MAX_N][MAX_N];

void f(int n){
    if(n==1){
        ans[0][0]=1;
        return;
    }
    int mid=n/2;
    f(mid);
    for(int i=0;i<mid;i++){
        for(int j=0;j<mid;j++){
            //(3)
            ans[i+mid][j]=ans[i][j]+mid;
            //(2)
            ans[i][j+mid]=ans[i+mid][j];
            //(4)
            ans[i+mid][j+mid]=ans[i][j];
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	while(cin>>n){
		f(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<'\n';
        }
	}
	return 0;
}