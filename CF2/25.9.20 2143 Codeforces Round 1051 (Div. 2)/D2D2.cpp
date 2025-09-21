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
const int MAX_N = 3000+10;

int T=1;
int n;
int a[MAX_N],b[MAX_N];
int bitlin[MAX_N][MAX_N],bitcol[MAX_N][MAX_N];

void update_lin(int lin,int pos,int val){
	pos++;
	for(int i=pos;i<=n+1;i+=(i&-i))
		bitlin[lin][i]=(bitlin[lin][i]+val)%mod;
}

void update_col(int col,int pos,int val){
	pos++;
	for(int i=pos;i<=n+1;i+=(i&-i))
		bitcol[col][i]=(bitcol[col][i]+val)%mod;
}

int query_lin(int lin,int pos){
	pos++;
	int r=0;
	for(int i=pos;i>0;i-=(i&-i))
		r=(r+bitlin[lin][i])%mod;
	return r;
}

int query_col(int col,int pos){
	pos++;
	int r=0;
	for(int i=pos;i>0;i-=(i&-i))
		r=(r+bitcol[col][i])%mod;
	return r;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>b[i];
		for(int i=1;i<=n;i++){
			a[i]=1;
			for(int j=1;j<i;j++)
				if(b[j]<=b[i])
					a[i]++;
			for(int j=i+1;j<=n;j++)
				if(b[j]<b[i])
					a[i]++;
		}
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				bitlin[i][j]=bitcol[i][j]=0;
		update_lin(0,0,1);
		update_col(0,0,1);
		for(int i=1;i<=n;i++){
			vector<pair<int,pair<int,int>>> bufs;
			int x=a[i];
			for(int j=x+1;j<=n;j++){
				int lin,col,buf;
				lin=j;
				col=x;
				buf=query_lin(j,x-1);
				bufs.push_back({buf,{lin,col}});
			}
			for(int k=0;k<x;k++){
				int lin,col,buf;
				lin=x;
				col=k;
				buf=query_col(k,x-1);
				bufs.push_back({buf,{lin,col}});
			}
			for(auto it:bufs){
				update_lin(it.second.first,it.second.second,it.first);
				update_col(it.second.second,it.second.first,it.first);
			}
		}
		int ans=0;
		for(int lin=0;lin<=n;lin++)
			ans=(ans+query_lin(lin,n))%mod;
		cout<<ans<<'\n';
	}
	return 0;
}