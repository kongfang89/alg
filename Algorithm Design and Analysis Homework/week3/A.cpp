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
/*题解：
先假设每个选手第一天要和自己打一场
再将n*n的日程表分解为四宫格，可以有如下策略：
    左上：1~n/2打1~n/2
    右上：1~n/2打n/2+1~n
    左下：n/2+1~n打n/2+1~n
    右下：n/2+1~n打1~n/2
故只需要计算左上，即可推出其他三个宫格的情况：
    左上=右下
    左下=右上
    左上+n/2=左下
    右下+n/2=右上
*/
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
            //左下
            ans[i+mid][j]=ans[i][j]+mid;
            //右上
            ans[i][j+mid]=ans[i+mid][j];
            //右下
            ans[i+mid][j+mid]=ans[i][j];
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    // cin>>T;
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