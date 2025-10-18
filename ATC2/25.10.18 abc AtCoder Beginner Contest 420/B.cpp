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
const int MAX_N = 110;

int T=1;
int n,m;
string s[MAX_N];
int A[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>s[i];
        for(int i=0;i<m;i++){
            int cnt0=0,cnt1=0;
            for(int j=0;j<n;j++){
                if(s[j][i]=='0')
                    cnt0++;
                else
                    cnt1++;
            }
            if(cnt0==0||cnt1==0)
                continue;
            char c;
            if(cnt0<cnt1)
                c='0';
            else
                c='1';
            for(int j=0;j<n;j++){
                if(s[j][i]==c)
                    A[j]++;
            }
        }
        int ma=0;
        for(int i=0;i<n;i++)
            ma=max(ma,A[i]);
        for(int i=0;i<n;i++)
            if(A[i]==ma)
                cout<<i+1<<' ';
        cout<<'\n';
	}
	return 0;
}