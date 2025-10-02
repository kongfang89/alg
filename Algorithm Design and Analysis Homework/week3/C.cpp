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
const int MAX_N = 200010;

int T=1;
//点的结构体 
struct point{
	double x,y;
    int id;
}p[MAX_N];
vector<pair<double,pair<int,int>>> ans;
//点的个数，存放两个平面中间部分的点的编号 
int n,a[MAX_N];
//点排序函数（一开始垂直划分两个平面 
bool cmp1(point a,point b){
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}
//点排序函数，在确定两个平面的最小距离mind后，根据垂直划分线左右mind的区域中的点，需要再根据y值排序，以便筛除两点y值相差超过mind的点 
bool cmp2(int a,int b){
	return p[a].y<p[b].y;
}
//计算两点距离 
double dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(int l,int r){
	//如果区间只剩一个点，直接返回INF，因为没有两点距离 
	if(l==r)
		return INF;
	//如果区间只剩两个点，直接返回两点距离 
	if(l+1==r){
        ans.push_back({dist(p[l],p[r]),{min(p[l].id,p[r].id),max(p[l].id,p[r].id)}});
        return dist(p[l],p[r]);
    }
	//否则根据中间的点垂直划分出两个平面 
	int mid=(l+r)/2;
	//继续递归 
	double d1=solve(l,mid);
	double d2=solve(mid+1,r);
	//获取左右平面小的距离
	double mind=min(d1,d2);
	//统计划分线左右mind的区间的点，并把编号记录在a数组中 
	int cnt=0;
	for(int i=l;i<=r;i++)
		if(fabs(p[mid].x-p[i].x)<=mind)
			a[++cnt]=i;
	//根据y值排序 
	sort(a+1,a+cnt+1,cmp2);
	//遍历找最小距离
	//获取第一个点 
	for(int i=1;i<=cnt;i++)
		//获取第一个点后面所有的点（如果两点y值之差超过mind，筛去） 
		for(int j=i+1;j<=cnt&&p[a[j]].y-p[a[i]].y<=mind;j++)
			//计算并更新最小值 
			if(dist(p[a[j]],p[a[i]])<mind){
                mind=dist(p[a[i]],p[a[j]]);
                ans.push_back({mind,{min(p[a[i]].id,p[a[j]].id),max(p[a[i]].id,p[a[j]].id)}});
            }
	//返回 
	return mind;
}

int cmp(pair<double,pair<int,int>> a,pair<double,pair<int,int>> b){
    if(a.first==b.first){
        if(a.second.first==b.second.first)
            return a.second.second<b.second.second;
        return a.second.first<b.second.first;
    }
    return a.first<b.first;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>p[i].x>>p[i].y;
            p[i].id=i-1;
        }
        sort(p+1,p+n+1,cmp1);
        double ansd=solve(1,n);
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans[0].second.first<<' '<<ans[0].second.second<<'\n';
        ans.clear();
    }
	return 0;
}