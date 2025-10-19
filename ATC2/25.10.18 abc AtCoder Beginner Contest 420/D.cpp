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
const int MAX_N = 510;

int T=1;
int h,w;
char M[MAX_N][MAX_N];
int sx,sy,gx,gy;
int dp[2][MAX_N][MAX_N];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>h>>w;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				cin>>M[i][j];
				if(M[i][j]=='S')
					sx=i,sy=j;
				if(M[i][j]=='G')
					gx=i,gy=j;
			}
		memset(dp,0x3f,sizeof(dp));
		dp[0][sx][sy]=0;
        queue<tuple<int,int,int>> Q;
		Q.push({0,sx,sy});
		while(!Q.empty()){
			auto [t,x,y]=Q.front();
			Q.pop();
			for(int i=0;i<4;i++){
				int nx=x+dx[i],ny=y+dy[i];
				if(nx<0||nx>=h||ny<0||ny>=w)
					continue;
				if(M[nx][ny]=='#')
					continue;
				if(t==0&&M[nx][ny]=='x')
					continue;
				if(t==1&&M[nx][ny]=='o')
					continue;
				int tt=t^(M[nx][ny]=='?');
				if(dp[tt][nx][ny]!=0x3f3f3f3f)
					continue;
				Q.push({tt,nx,ny});
				dp[tt][nx][ny]=dp[t][x][y]+1;
			}
		}
        int ans=min(dp[0][gx][gy],dp[1][gx][gy]);
		if(ans==0x3f3f3f3f)
			cout<<-1<<'\n';
		else
			cout<<ans<<'\n';
	}
	return 0;
}