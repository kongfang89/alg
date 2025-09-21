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
const int MAX_N = 1;

int T=1;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		int n;
		string s;
		cin>>n;
		cin>>s;
		if(n&1){
			cout<<-1<<'\n';
			continue;
		}
		int m=n>>1;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='('){
				if(i&1)
					cnt--;
				else
					cnt++;
			}
		}
		if(cnt<2-m||cnt>m||((cnt-m)&1)){
			cout<<-1<<'\n';
			continue;
		}
		int t;
		if(cnt>=0)
			t=m-cnt;
		else
			t=cnt+m-1;
		string ans;
		for(int i=0;i<t;i++)
			ans+='(';
		for(int i=0;i<m-t;i++)
			ans+="()";
		for(int i=0;i<t;i++)
			ans+=')';
		cout<<ans<<'\n';
	}
	return 0;
}