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
/*题解：
设矩阵A=(1 1) f[i]表示斐波那契数列的第i个数
        (1 0)
注意到(f[n] f[n-1])*A=(f[n]+f[n-1] f[n])=(f[n+1] f[n])
则(f[2] f[1])*(A^n-2)=(f[n] f[n-1])
其中A^n-2用矩阵快速幂实现即可
*/
int T=1;
struct Mat{
	ll c[MAX_N][MAX_N];
}I,A,F;

ll n;

inline void init(){
    memset(I.c,0,sizeof(I.c));
    memset(A.c,0,sizeof(A.c));
    memset(F.c,0,sizeof(F.c));
    for(int i=1;i<=2;i++)
		I.c[i][i]=1;
    A.c[1][1]=1,A.c[1][2]=1;
	A.c[2][1]=1,A.c[2][2]=0;
	for(int i=1;i<=2;i++)
		F.c[i][1]=1;
}

Mat operator*(const Mat &x,const Mat &y){
	Mat z;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			z.c[i][j]=0;
	for(int i=1;i<=2;i++)
		for(int j=1;j<=2;j++)
			for(int k=1;k<=2;k++){
				z.c[i][j]+=(x.c[i][k]%mod)*(y.c[k][j]%mod)%mod;
				z.c[i][j]%=mod;
			}
	return z;
}

Mat mat_ksm(Mat A,ll n){
    Mat res=I;
    while(n){
        if(n&1)
            res=res*A;
        A=A*A;
        n>>=1;
    }
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	init();
    while(cin>>n){
    	if(n<=2){
	        cout<<1<<'\n';
	        continue;
	    }
	    Mat ans=mat_ksm(A,n-2);
	    ans=ans*F;
	    cout<<ans.c[1][1]<<'\n';
    }
	return 0;
}