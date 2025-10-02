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
const int MAX_N = 1e5+10;
//题解：模拟题，递归实现仿蝴蝶变换即可
int T=1;
int n,a[MAX_N],b[MAX_N];

void ButterflyTrans(int l,int r){
	if(l==r)
		return;
	int mid=l+r>>1;
	for(int i=l,j=l;i<=mid;i++,j+=2)
		b[i]=a[j];
	for(int i=mid+1,j=l+1;i<=r;i++,j+=2)
		b[i]=a[j];
	for(int i=l;i<=r;i++)
		a[i]=b[i];
	ButterflyTrans(l,mid);
	ButterflyTrans(mid+1,r);
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ButterflyTrans(1,n);
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" \n"[i==n];
	}
	return 0;
}