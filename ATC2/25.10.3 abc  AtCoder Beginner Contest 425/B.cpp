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
const int MAX_N = 1;

int T=1;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<int> a(n+1),vis(n+1);
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==-1)
				continue;
			if(vis[a[i]])
				flag=0;
			vis[a[i]]=1;
		}
		if(flag){
            YES;
            vector<int> t;
            for(int i=1;i<=n;i++){
                if(vis[i]==0)
                    t.push_back(i);
            }
            for(int i=1;i<=n;i++){
                if(a[i]==-1){
                    cout<<t.back()<<' ';
                    t.pop_back();
                }
                else{
                    cout<<a[i]<<' ';
                }
            }
        }
		else
			NO;
	}
	return 0;
}