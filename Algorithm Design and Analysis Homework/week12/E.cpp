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
//题解：枚举前两个数的长度，然后验证后续数字能否凑成斐波那契数列
int T=1;
string s;
int n;

ll string2long(const string& str){
	if(str.empty()||(str.length()>1&&str[0]=='0'))
		return -1;
	if(str.length()>10)
		return -1;
	ll res=0;
	for(char c:str){
		res=res*10+(c-'0');
		if(res>INT_MAX)
			return -1;
	}
	return res;
}

vector<ll> check(ll x1,ll x2,int pos){
	vector<ll> res={x1,x2};
	while(pos<n){
		ll next=x1+x2;
		if(next>INT_MAX)
			return {};
		string strnext=to_string(next);
		if(pos+strnext.size()>n)
			return {};
		if(s.substr(pos,strnext.size())!=strnext)
			return {};
		res.push_back(next);
		pos+=strnext.size();
		x1=x2;
		x2=next;
	}
	return res;
}

vector<ll> split(){
	for(int len1=1;len1<=min(10,n-2);len1++){
		string s1=s.substr(0,len1);
		ll x1=string2long(s1);
		if(x1==-1)
            continue;
		for(int len2=1;len2<=min(10,n-len1-1);len2++){
			string s2=s.substr(len1,len2);
			ll x2=string2long(s2);
			if(x2==-1)
                continue;
			vector<ll> res=check(x1,x2,len1+len2);
			if(!res.empty()&&res.size()>=3)
				return res;
		}
	}
	return {};
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>s){
		n=s.length();
		vector<ll> ans=split();
		if(ans.empty()){
			cout<<"None\n";
		}
        else{
			for(auto x:ans)
                cout<<x<<' ';
            cout<<'\n';
		}
	}
	return 0;
}