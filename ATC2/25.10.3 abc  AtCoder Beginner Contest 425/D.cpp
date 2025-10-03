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
const int MAX_N = 3e5+10;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int T=1;
int h,w;
string s[MAX_N];

int count(int x,int y){
    int cnt=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w)
            continue;
        if(s[nx][ny]=='#')
            cnt++;
    }
    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
        cin>>h>>w;        
        for(int i=0;i<h;i++)
            cin>>s[i];
        vector<pair<int,int>> S;
        for(int i=0;i<h*w;i++){
            if(i==0){
                S.clear();
                for(int i=0;i<h;i++)
                    for(int j=0;j<w;j++)
                        if(s[i][j]=='.'&&count(i,j)==1)
                            S.push_back({i,j});
            }
            else{
                vector<pair<int,int>> NS;
                for(auto [x,y]:S){
                    for(int i=0;i<4;i++){
                        int nx=x+dx[i],ny=y+dy[i];
                        if(nx<0||nx>=h||ny<0||ny>=w)
                            continue;
                        if(s[nx][ny]=='.'&&count(nx,ny)==1)
                            NS.push_back({nx,ny});
                    }
                }
                S=NS;
            }
            if(S.size()==0)
                break;
            for(auto [x,y]:S)
                s[x][y]='#';
        }
        int ans=0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
                ans+=(s[i][j]=='#');
        cout<<ans<<'\n';
	}
	return 0;
}