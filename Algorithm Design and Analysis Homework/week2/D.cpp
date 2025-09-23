#include <bits/stdc++.h>
#define INF 99999999
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAX_N=5;
const int MOD=1e9+7;

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
				z.c[i][j]+=(x.c[i][k]%MOD)*(y.c[k][j]%MOD)%MOD;
				z.c[i][j]%=MOD;
			}
	return z;
}

Mat mat_ksm(Mat A,ll n){
    Mat II=I;
    while(n){
        if(n&1)
            II=II*A;
        A=A*A;
        n>>=1;
    }
    return II;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	//freopen("1.out","w",stdout);
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

/*
样例
5
输出
5
*/
