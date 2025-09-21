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
int n;
int a[MAX_N];

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int l=0,r=n-1;
        int now=1;
        int flag=1;
        while(l<r){
            if(a[l]==now){
                l++;
                now++;
            }
            else if(a[r]==now){
                r--;
                now++;
            }                
            else{
                flag=0;
                break;
            }
        }
        if(flag)
            YES;
        else
            NO;
	}
	return 0;
}