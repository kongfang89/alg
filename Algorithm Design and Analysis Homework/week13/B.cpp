#include <bits/stdc++.h>
#define INF INT_MAX
#define LINF LLONG_MAX 
#define YES cout<<"true"<<'\n'
#define NO cout<<"false"<<'\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1;
//题解：暴力枚举分割点，判断三段是否均为回文串
int T=1;
char t1,t2;
string s;

int check(string s){
    string t=s;
    reverse(t.begin(),t.end());
    return t==s;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>t1>>t2>>s){
        s=s.substr(1,s.size()-2);
        int n=s.size();
        int flag=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string s1=s.substr(0,i);
                string s2=s.substr(i,j-i+1);
                string s3=s.substr(j+1,n-j-1);
                if(check(s1)&&check(s2)&&check(s3)){
                    YES;
                    flag=1;
                }
                    
            }
        }
        if(!flag)
            NO;
	}
	return 0;
}