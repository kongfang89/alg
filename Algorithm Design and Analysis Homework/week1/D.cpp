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
注意到本题没有除法，可以先算乘法再算加减法，减法可以转化为加法
从前往后遍历，每遇到一个乘法，以当前为起点往后遍历连续的乘法，起点乘以后面每个数，同时把后面的数改为0
最后对数组求和就是答案
*/
int T=1;
int n;
ll a[MAX_N],ans=0;
char b[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n-1;i++){
			cin>>b[i];
			if(b[i]=='-'){
				b[i]='+';
				a[i+1]=-a[i+1];
			}
		}
		for(int i=0;i<n-1;i++){
			if(b[i]=='*'){
				int j=i;
				while(b[j]=='*'){
					a[i]*=a[j+1];
					a[j+1]=0;
					j++;
				}
				i=j-1;
			}
		}
        for(int i=0;i<n;i++)
            ans+=a[i];
        cout<<ans<<endl;
	}
	return 0;
}