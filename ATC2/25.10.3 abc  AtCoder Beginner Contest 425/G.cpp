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
const int MAX_N = 2e5+10;

int T=1;
int n,m;
ll ans;

void solve(vector<pair<int,int>> Q,vector<int> a,int k){
    if(k==-1)
        return;
    vector<int> L,R;
    vector<pair<int,int>> QL,QR;
    for(auto i:a){
        if(i&(1<<k))
            R.push_back(i);
        else
            L.push_back(i);
    }
    sort(Q.begin(),Q.end());
    int len=Q.size();
    for(int i=0;i<len;i++){
        int r=Q[i].first;
        int v=Q[i].second;
        while(i+1<len&&Q[i+1].first==r){
            v+=Q[i+1].second;
            i++;
        }
        if(r<=(1<<k)){
            if(L.empty()){
                ans+=1ll*(1<<k)*r*v;
                QR.push_back({r,v});
            }
            else
                QL.push_back({r,v});
        }
        else{
            if(L.empty()){
                ans+=1ll*(1<<k)*v*(1<<k);
                QR.push_back({(1<<k),v});
            }
            else
                QL.push_back({(1<<k),v});
            if(R.empty()){
                ans+=1ll*(1<<k)*v*(r-(1<<k));
                QL.push_back({r-(1<<k),v});
            }
            else
                QR.push_back({r-(1<<k),v});
        }
    }
    if(!QL.empty()&&!L.empty())
        solve(QL,L,k-1);
    if(!QR.empty()&&!R.empty())
        solve(QR,R,k-1);
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        vector<int> a(n);
        vector<pair<int,int>> Q;
        for(int i=0;i<n;i++)
            cin>>a[i];
        Q.push_back({m,1});
        solve(Q,a,30);
        cout<<ans<<'\n';
	}
	return 0;
}