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
const int MAX_N = 20;

int T=1;
int n,m,M[MAX_N][MAX_N],ans;
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};

void cover(int x,int y,int val){
    for(int k=0;k<5;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx>=0&&nx<n&&ny>=0&&ny<m)
            M[nx][ny]+=val;
    }
}

void dfs(int cnt,int rest){
    if(cnt>=ans)
        return;
    if(rest==0){
        ans=cnt;
        return;
    }
    if(cnt+(rest+4)/5>=ans)
        return;
    int x=-1,y=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(M[i][j]==0){
                x=i;
                y=j;
                break;
            }
    vector<pair<int,pair<int,int>>> v;
    for(int k=0;k<5;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(nx>=0&&nx<n&&ny>=0&&ny<m){
            int zero=0;
            for(int kk=0;kk<5;kk++){
                int tx=nx+dx[kk];
                int ty=ny+dy[kk];
                if(tx>=0&&tx<n&&ty>=0&&ty<m&&M[tx][ty]==0)
                    zero++;
            }
            v.push_back({-zero,{nx,ny}});
        }
    }
    sort(v.begin(),v.end());
    for(auto &op:v){
        int nx=op.second.first;
        int ny=op.second.second;
        int zero=-op.first;
        cover(nx,ny,1);
        dfs(cnt+1,rest-zero);
        cover(nx,ny,-1);
        if(ans==cnt+1+(rest-zero+4)/5)
            break;
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
        cin>>n>>m;
		ans=n*m;
		dfs(0,n*m);
		cout<<ans<<'\n';
	}
	return 0;
}