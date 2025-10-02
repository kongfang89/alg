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
const int MAX_N = 5e7+10;
/*题解：
快速排序每一轮可以确定一个数的位置pos(1<=pos<=n)
若pos=k，结束
若pos>k，则在(1,pos)找第k大
若pos<k，则在(pos+1,n)找第k-pos大
所以不需要真的实现快排，否则时间复杂度o(nlogn)无法通过本题
*/
int T=1;
int n,m,k;
int a[MAX_N];

int QuickSort(int l,int r,int k){
	if(l==r)
		return a[l];
	int ll=l,rr=r,p=a[l];
	while(ll<rr){
		while(ll<rr&&a[rr]>=p)
			--rr;
		a[ll]=a[rr];
		while(ll<rr&&a[ll]<=p)
			++ll;
		a[rr]=a[ll];
	}
	a[ll]=p;	
	if(ll-l+1==k)
		return a[ll];
	else if(ll-l+1>k)
		return QuickSort(l,ll,k);
	else
		return QuickSort(ll+1,r,k-(ll-l+1));
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>m>>k){
		a[0]=m;
		for(int i=1;i<n;i++)
			a[i]=1ll*a[i-1]*m%mod;
		cout<<QuickSort(0,n-1,k)<<'\n';
	}
	return 0;
}