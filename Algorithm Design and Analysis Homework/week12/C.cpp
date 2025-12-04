#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 100003;
//const int mod = 998244353;
const int MAX_N = 30;
//题解：(i,j)的路径数=(i-1,j)的路径数+(i,j-1)的路径数
int T=1;
int n,m;
ll a[MAX_N][MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
        cin>>n>>m;
        a[1][1]=1;
        for(int i=1;i<=n;i++)
        	for(int j=1;j<=m;j++){
        		if(i==1&&j==1)
        			continue;
        		a[i][j]=a[i-1][j]+a[i][j-1];	
			}
		cout<<a[n][m]<<'\n';
	}
	return 0;
}