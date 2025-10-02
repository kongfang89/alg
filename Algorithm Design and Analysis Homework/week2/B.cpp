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
/*题解：
归并排序合并两个有序数组为新的有序数组时，可以同时计算整个数组的逆序对
例如：1 3 5 7 | 2 4 6 8
合并过程：
1) 1 | 3 5 7 | 2 4 6 8
第一轮取前面数组的1，不会产生逆序
2) 1 2 | 3 5 7 | 4 6 8
第二轮取后面数组的2，则2与3 5 7产生逆序
3) 1 2 3 | 5 7 | 4 6 8
第二轮取前面数组的3，不会产生逆序
以此类推...
只需要在每次合并的时候，计算后面的有序数组每个元素产生的逆序对数即可
*/
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