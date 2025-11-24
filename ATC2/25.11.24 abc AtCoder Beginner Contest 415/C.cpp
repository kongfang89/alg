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
const int MAX_N = (1<<18)+10;

int T=1;
int n;
string s;
int vis[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		cin>>s;
		s=" "+s;
		for(int i=1;i<=(1<<n);i++)
			vis[i]=0;
		queue<int> q;
		for(int i=0;i<n;i++)
			if(s[(1<<i)]=='0')
				q.push(1<<i);
		int flag=0;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			if(now==(1<<n)-1){
				YES;
				flag=1;
				break;
			}
			for(int i=0;i<n;i++){
				if(now&(1<<i))
					continue;
				if(s[now+(1<<i)]=='0'&&!vis[now+(1<<i)]){
					vis[now+(1<<i)]=1;
					q.push(now+(1<<i));
				}
			}
		}
		if(!flag)
			NO;
	}
	return 0;
}