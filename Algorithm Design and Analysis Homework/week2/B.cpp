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

int T=1;
int n;
int a[MAX_N],t[MAX_N];

int MergeSort(int l,int r){
	if(l==r)
		return 0;
	int mid=l+r>>1;
	int res=0;
	res+=MergeSort(l,mid);
	res+=MergeSort(mid+1,r);
	for(int i=l;i<=r;i++)
		t[i]=a[i];
	int i=l,j=mid+1,k=l;
	while(i<=mid&&j<=r){
		if(t[i]<=t[j]){
			a[k++]=t[i++];
		}
		else{
			a[k++]=t[j++];
			res+=mid-i+1;
		}
	}
	while(i<=mid){
		a[k++]=t[i++];
	}
	while(j<=r){
		a[k++]=t[j++];
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<MergeSort(1,n)<<'\n';
	}
	return 0;
}