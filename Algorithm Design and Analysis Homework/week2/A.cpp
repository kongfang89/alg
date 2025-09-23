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
int n;
string s="ABC";

void Hannoi(int a,int b,int c,int n){
	if(n==1)
		cout<<"Move disk 1 from "<<s[a]<<" to "<<s[c]<<"\n";
	else{
		Hannoi(a,c,b,n-1);
		cout<<"Move disk "<<n<<" from "<<s[a]<<" to "<<s[c]<<"\n";
		Hannoi(b,a,c,n-1);
	}
}


int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		Hannoi(0,1,2,n);
	}
	return 0;
}