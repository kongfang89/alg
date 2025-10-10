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

ll rt,ct,ra,ca;
ll n,m,l;
string s,t;

ll now;
vector<ll> tim;
map<char,ll> dx,dy;
ll ans;
int i,j;

struct node{
    char c;
    ll len;
};
vector<node> op1,op2;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
    dx['U']=-1;dx['D']=1;dx['L']=0;dx['R']=0;
    dy['U']=0;dy['D']=0;dy['L']=-1;dy['R']=1;
    cin>>rt>>ct>>ra>>ca;
    cin>>n>>m>>l;
    now=0;
    for(int i=1;i<=m;i++){
        char x;
        ll y;
        cin>>x>>y;
        now+=y;
        op1.push_back({x,now});
        tim.push_back(now);
    }
    now=0;
    for(int i=1;i<=l;i++){
        char x;
        ll y;
        cin>>x>>y;
        now+=y;
        op2.push_back({x,now});
        tim.push_back(now);
    }
    sort(tim.begin(), tim.end());
    tim.erase(unique(tim.begin(), tim.end()), tim.end());
    i=0,j=0;
    now=0;
    for(auto end:tim){
        if(op1[i].len>=end){
            s+=op1[i].c;
        }
        else{
            i++;
            s+=op1[i].c;
        }
        if(op2[j].len>=end){
            t+=op2[j].c;
        }
        else{
            j++;
            t+=op2[j].c;
        }
    }
    i=0,j=0;
    now=0;
    for(auto end:tim){
        if(rt!=ra&&ct!=ca){
            ll dr=abs(rt-ra),dc=abs(ct-ca);
            rt+=dx[s[i]];
            ct+=dy[s[i]];
            ra+=dx[t[j]];
            ca+=dy[t[j]];
            if(dr==dc&&(end-now)>=dr){
                if(dr>abs(rt-ra)&&dc>abs(ct-ca))
                    ans++;
            }
            rt+=(end-now-1)*dx[s[i]];
            ct+=(end-now-1)*dy[s[i]];
            ra+=(end-now-1)*dx[t[j]];
            ca+=(end-now-1)*dy[t[j]];
        }
        else if(rt==ra&&ct==ca){
            if(s[i]==t[j]){
                ans+=(end-now);
            }
            rt+=(end-now)*dx[s[i]];
            ct+=(end-now)*dy[s[i]];
            ra+=(end-now)*dx[t[j]];
            ca+=(end-now)*dy[t[j]];
        }
        else{
            ll d=max(abs(rt-ra),abs(ct-ca));
            rt+=dx[s[i]];
            ct+=dy[s[i]];
            ra+=dx[t[j]];
            ca+=dy[t[j]];
            if(d%2==0&&(end-now)>=d/2&&d>max(abs(rt-ra),abs(ct-ca))&&min(abs(rt-ra),abs(ct-ca))==0)
                ans++;
            rt+=(end-now-1)*dx[s[i]];
            ct+=(end-now-1)*dy[s[i]];
            ra+=(end-now-1)*dx[t[j]];
            ca+=(end-now-1)*dy[t[j]];
        }
        now=end;
        i++;
        j++;
    }
    cout<<ans<<'\n';
	return 0;
}