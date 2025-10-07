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
int k,len,inner;
string s,ans;
int pw[10];

int ksm(int x,int n){
    int res=1;
    while(n){
        if(n&1)
            res=1ll*res*x%k;
        x=1ll*x*x%k;
        n>>=1;
    }
    return res;
}

string itos(int x,int len){
    string res;
    for(int i=1;i<=len;i++){
        res.push_back('0'+(x%10));
        x/=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

ll exgcd(ll a,ll b,ll &x,ll &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    ll g=exgcd(b,a%b,x,y);
    ll t=x;
    x=y;
    y=t-(a/b)*y;
    return g;
}

void solve1(int u,int l){
    int pw10=ksm(10,l+len);
    for(int up=0;up<=pw[u]-1;up++){
        int t=(1ll*up*pw10%k+1ll*inner*pw[l]%k)%k;
        int lw=(k-t)%k;
        if(lw<pw[l])
            ans=min(ans,itos(up,u)+s+itos(lw,l));
    }
}

void solve2(int u,int l){
    int pw10=ksm(10,l+len);
    for(int lw=0;lw<=pw[l]-1;lw++){
        int t=(1ll*inner*pw[l]%k+lw)%k;
        t=(k-t)%k;
        ll up=0,y=0;
        ll g=exgcd(pw10,k,up,y);
        if(t%g)
            continue;
        up*=t/g;
        up=(up%(k/g)+(k/g))%(k/g);
        if(up<pw[u])
            ans=min(ans,itos(up,u)+s+itos(lw,l));
    }
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
    pw[0]=1;
    for(int i=1;i<=9;i++)
        pw[i]=pw[i-1]*10;
	while(T--){
		cin>>k>>s;
        len=s.length();
        ans.clear();
        ans.assign(len+9,'9');
        inner=0;
        for(int i=0;i<len;i++)
            inner=(10ll*inner+s[i]-'0')%k;
        for(int lower=0;lower<=9;lower++){
            int upper=9-lower;
            if(upper<=lower)
                solve1(upper,lower);
            else
                solve2(upper,lower);
        }
        int flag=1;
        for(auto i:ans){
            if(flag&&i=='0')
                continue;
            flag=0;
            cout<<i;
        }
        if(flag)
            cout<<0;
        cout<<'\n';
	}
	return 0;
}