#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"Yes"<<endl
#define NO cout<<"No"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 20;

int T=1;
int h,w;
string s[MAX_N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int check(int x,int y){
	int res=0;
	for(int i=0;i<4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if(nx<0||nx>=h||ny<0||ny>=w)
			continue;
		if(s[nx][ny]=='#')
            res++;
	}
    return (res==4||res==2);
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>h>>w;
		for(int i=0;i<h;i++)
			cin>>s[i];
        int flag=1;
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(s[i][j]=='#'&&!check(i,j))
					flag=0;
		if(flag)
			YES;
		else
			NO;
	}
	return 0;
}