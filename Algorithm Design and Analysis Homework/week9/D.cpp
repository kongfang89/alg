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
const int MAX_N = 1;
const double eps=1e-10;

int T=1;

struct Simplex{
	double z;
	vector<vector<double>> a;
	vector<double> b,c;
	int n,m;
	void init(int _n,int _m){
		n=_n,m=_m,z=0;
		a.resize(m+10,vector<double>(n+10,0));
		b.resize(m+10,0);
		c.resize(n+10,0);
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
int s[10010],t[10010];
Simplex spx;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
		spx.init(n,m);
		for(int i=0;i<n;i++)
            cin>>spx.c[i];
        for(int i=0;i<m;i++)
			cin>>s[i]>>t[i]>>spx.b[i];
        for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				spx.a[i][j]=j>=s[i]-1&&j<=t[i]-1;
        cout<<(int)(spx.solve()+eps)<<'\n';
	}
	return 0;
}
