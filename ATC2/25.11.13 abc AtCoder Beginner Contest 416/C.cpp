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
int n,k,x;
string s[MAX_N];

priority_queue<string,vector<string>,greater<string>> pq;

void dfs(int now,string t){
	if(now==k+1){
		pq.push(t);
		return;
	}
	for(int i=1;i<=n;i++)
		dfs(now+1,t+s[i]);
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>k>>x;
		for(int i=1;i<=n;i++)
			cin>>s[i];
		dfs(1,"");
		int cnt=0;
		while(!pq.empty()){
			cnt++;
			if(cnt==x){
				cout<<pq.top()<<'\n';
				return 0;
			}
			pq.pop();
		}
	}
	return 0;
}