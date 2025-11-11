#include <bits/stdc++.h>
#define INF 1e18
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1010;
const double eps=1e-10;
//题解：使用单纯形算法求解
int T=1;

struct Simplex{
	double a[MAX_N][MAX_N],b[MAX_N],c[MAX_N],z;
	int n,m;
	void init(int _n,int _m){
		n=_n,m=_m,z=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
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
			a[i][e]=-a[i][e]*a[l][e];
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
			double minba=INF;
			for(int i=0;i<m;i++){
				if(a[i][e]>eps&&minba>b[i]/a[i][e]){
					minba=b[i]/a[i][e];
					l=i;
				}
			}
			if(l==-1)
				return INF;
			pivot(l,e);
		}
	}
};

int n,m;
Simplex spx;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
//	cin>>T;
	while(T--){
		cin>>n>>m;
		spx.init(n,m);
		for(int i=0;i<n;i++)
			cin>>spx.c[i];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++)
				cin>>spx.a[i][j];
			cin>>spx.b[i];
		}
		cout<<fixed<<setprecision(6)<<spx.solve()<<'\n';
	}
	return 0;
}
