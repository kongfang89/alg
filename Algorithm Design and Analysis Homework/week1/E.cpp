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
//题解：模拟题，注意输出不一定是五个人就行
int T=1;
int n;
ll a[MAX_N];
int id[5],cnt=0;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(cnt==0){
                id[cnt++]=i;
            }
            else if(cnt<5){
                if(a[i]>a[id[cnt-1]])
                id[cnt++]=i;
            }
            else if(cnt==5){
                if(a[i]>a[id[4]]){
                    id[0]=id[1];
                    id[1]=id[2];
                    id[2]=id[3];
                    id[3]=id[4];
                    id[4]=i;
                }
            }
        }
        for(int i=0;i<5;i++){
            if(id[i])
                cout<<id[i]<<' ';
        }
        cout<<endl;
	}
	return 0;
}