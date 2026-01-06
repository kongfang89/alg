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
ll a,n;

int check(string s){
	string t=s;
    reverse(t.begin(),t.end());
    return s==t;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>a>>n;
		ll ans=0;
        vector<ll> v;
		for(int i=1;i<=999999;i++){
            string s=to_string(i);
            string t=s;
            reverse(t.begin(),t.end());
            s+=t;
            ll sum=0;
            for(int j=s.size()-1;j>=0;j--)
                sum+=pow(10,s.size()-1-j)*(s[j]-'0');
            v.push_back(sum);
        }
        for(int i=1;i<=999999;i++){
            string t=to_string(i);
            string s="";
            for(int j=0;j<t.size();j++)
                s+=t[j];
            for(int j=t.size()-2;j>=0;j--)
                s+=t[j];
            ll sum=0;
            for(int j=s.size()-1;j>=0;j--)
                sum+=pow(10,s.size()-1-j)*(s[j]-'0');
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        for(auto i:v){
            if(i>n)
                break;
            ll j=i;
            string s="";
            while(j){
                s+=char(j%a+'0');
                j/=a;
            }
            if(check(s))
                ans+=i;
        }
        cout<<ans<<'\n';
	}
	return 0;
}