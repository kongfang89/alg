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
int money[10]={100, 50, 20, 10, 5, 2, 1};
//题解：贪心，面值大的先考虑
int T=1;
int n;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
        int tn=n;
		vector<pair<int,int>> ans;
		int tot=0;
		for(int i=0;i<7;i++){
			if(n>=money[i]){
				int cnt=n/money[i];
				n-=cnt*money[i];
				ans.push_back({money[i],cnt});
				tot+=cnt;
			}
		}
		cout<<tot<<' ';
		int m=ans.size();
		for(int i=0;i<m;i++){
            cout<<ans[i].first;
            if(ans[i].second>1)
                cout<<'*'<<ans[i].second;
            if(i==m-1)
                cout<<'=';
            else
                cout<<'+';
		}
        cout<<tn<<'\n';
	}
	return 0;
}