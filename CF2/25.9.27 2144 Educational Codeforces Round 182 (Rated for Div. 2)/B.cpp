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
int n,a[MAX_N],vis[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		vector<int> zero;
        for(int i=1;i<=n;i++)
            vis[i]=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!a[i])
				zero.push_back(i);
            vis[a[i]]=1;
		}
		if(zero.size()==1){
            for(int i=1;i<=n;i++)
                if(!vis[i])
                    a[zero[0]]=i;
        }
        int l=1,r=n;
        while(a[l]==l)
            l++;
        while(a[r]==r)
            r--;
        if(l<r)
            cout<<r-l+1<<'\n';
        else
            cout<<0<<'\n';
	}
	return 0;
}