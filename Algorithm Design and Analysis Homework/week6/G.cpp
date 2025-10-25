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
二分答案求最小分块和，可能的最小分块和为a数组最大值，最大分块和为a数组和
由于输出要求前面的块尽可能小，故从后往前分块，记录每个位置的分块号minBlocks
再从前往后遍历，如果：
1.剩余元素等于剩余块数，则必须分块
2.当前块和加上下一个元素超过了求出的最小分块和，则必须分块
3.后面剩余元素能满足剩余块数要求，为保证前面的块尽可能小，则必须分块
*/
int T=1;
int n,k;
ll a[MAX_N];

bool check(ll x){
    int cnt=1;
    ll now=0;
    for(int i=1;i<=n;i++){
        if(now+a[i]>x){
            cnt++;
            now=a[i];
        }
        else
            now+=a[i];
    }
    return cnt<=k;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(cin>>n>>k){
		for(int i=1;i<=n;i++)
            cin>>a[i];
        ll l=0,r=0;
        for(int i=1;i<=n;i++){
            l=max(l,a[i]);
            r+=a[i];
        }
        while(l<r){
            ll mid=(l+r)/2;
            if(check(mid))
                r=mid;
            else
                l=mid+1;
        }
        ll ans=l;
        vector<int> minBlocks(n+1,0);
        int cnt=1;
        ll sum=0;
        for(int i=n;i>=1;i--){
            if(sum+a[i]>ans){
                cnt++;
                sum=a[i];
            }
            else{
                sum+=a[i];
            }
            minBlocks[i]=cnt;
        }
        vector<bool> isSplit(n+1,false);
        int remain=k;
        ll now=0;
        for(int i=1;i<=n;i++){
            now+=a[i];
            if(i==n)
                break;
            if(n-i==remain-1){
                isSplit[i]=true;
                remain--;
                now=0;
            }
            else if(now+a[i+1]>ans){
                isSplit[i]=true;
                remain--;
                now=0;
            }
            else if(minBlocks[i+1]<=remain-1&&remain>1){
                isSplit[i]=true;
                remain--;
                now=0;
            }
        }
        for(int i=1;i<=n;i++){
            cout<<a[i];
            if(i<n){
                if(isSplit[i])
                    cout<<" / ";
                else
                    cout<<' ';
            }
        }
        cout<<'\n';
	}
	return 0;
}