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
const int pw[6]={1,6,36,216,1296,7776};

int T=1;
int A[6];
double f[4][6][7776];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		for(int i=0;i<6;i++)
			cin>>A[i];
		for(int n=0;n<=5;n++){
			for(int S=0;S<pw[n];S++){
				int tmp=S,cnt[6]={0};
				for(int j=0;j<n;j++){
					cnt[tmp%6]++;
					tmp/=6;
				}
				for(int P=0;P<pw[5-n];P++){
					tmp=P;
					int c[6];
					memcpy(c,cnt,sizeof(c));
					for(int j=0;j<5-n;j++){
						c[tmp%6]++;
						tmp/=6;
					}
					int score=0;
					for(int i=0;i<6;i++){
						int tot=0;
						for(int j=0;j<6;j++)
							if(A[i]==A[j])
								tot+=c[j];
						score=max(score,A[i]*tot);
					}
					f[1][n][S]+=score;
				}
				f[1][n][S]/=pw[5-n];
			}
		}
		for(int k=2;k<=3;k++){
			for(int n=0;n<=5;n++){
				for(int S=0;S<pw[n];S++){
					for(int P=0;P<pw[5-n];P++){
						double maxv=0;
						for(int K=0;K<(1<<(5-n));K++){
							int m=__builtin_popcount(K);
							int tmp=P,T=S;
							for(int i=0;i<5-n;i++){
								if(K>>i&1)
									T=T*6+(tmp%6);
								tmp/=6;
							}
							maxv=max(maxv,f[k-1][n+m][T]);
						}
						f[k][n][S]+=maxv;
					}
					f[k][n][S]/=pw[5-n];
				}
			}
		}
		cout<<fixed<<setprecision(10)<<f[3][0][0]<<'\n';
	}
	return 0;
}