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
const int MAX_N = 1010;
const double eps=1e-7;

int T=1;

struct Simplex{
	double a[MAX_N][MAX_N],b[MAX_N],c[MAX_N],z;
	int n,m;
	void init(int _n,int _m){
		n=_n,m=_m,z=0;
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
	}
	void pivot(int l,int e){
		b[l]/=a[l][e];
		for(int j=0;j<n;j++)
			if(j!=e)
				a[l][j]/=a[l][e];
		a[l][e]=1/a[l][e];
		for(int i=0;i<m;i++){
			if(i==l||a[i][e]>-eps&&a[i][e]<eps)
				continue;
			b[i]-=a[i][e]*b[l];
			for(int j=0;j<n;j++)
				if(j!=e)
					a[i][j]-=a[i][e]*a[l][j];
			a[i][e]-=a[i][e]*a[l][e];
		}
		z+=c[e]*b[l];
		for(int j=0;j<n;j++)
			if(j!=e)
				c[j]-=c[e]*a[l][j];
		c[e]*=-a[l][e];
	}
	double solve(){
		while(1){
			int e=-1,l=-1;
			double maxc=eps;
			for(int j=0;j<n;j++){
				if(c[j]>maxc){
					maxc=c[j];
					e=j;
				}
			}
			if(e==-1)
				return z;
			double minba=0x3f3f3f3f;
			for(int i=0;i<m;i++){
				if(a[i][e]>eps&&minba>b[i]/a[i][e]){
					minba=b[i]/a[i][e];
					l=i;
				}
			}
			if(l==-1)
				return 0x3f3f3f3f;
			pivot(l,e);
		}
	}
};

int n,m;
Simplex spx;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		n=5,m=3;spx.init(n,m);
		spx.c[0]=12,spx.c[1]=12;
		spx.a[0][0]=0.25,spx.a[0][1]=0.5;
		spx.a[1][0]=0.5,spx.a[1][1]=0.5;
		spx.a[2][0]=0.25,spx.a[2][1]=0;
		spx.b[0]=120,spx.b[1]=150,spx.b[2]=50;
		spx.solve();
		cout<<spx.z<<'\n';
	}
	return 0;
}