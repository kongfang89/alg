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
//题解：看注释
int T=1;
//点的结构体 
struct point{
	double x,y;
    int id;
}p[MAX_N];
//点的个数，存放两个平面中间部分的点的编号 
int n,a[MAX_N];
//算过的全存进ans，最后排序输出最小的（因为我不想每次更新mind的时候比序号大小= =）
struct node{
	double d;
	int id1,id2;
};
vector<node> ans;

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
        ans.push_back({dist(p[l],p[r]),min(p[l].id,p[r].id),max(p[l].id,p[r].id)});
        return ans.back().d;
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
			if(dist(p[a[j]],p[a[i]])<=mind){
                mind=dist(p[a[i]],p[a[j]]);
				int id1=min(p[a[i]].id,p[a[j]].id);
				int id2=max(p[a[i]].id,p[a[j]].id);
                ans.push_back({mind,min(p[a[i]].id,p[a[j]].id),max(p[a[i]].id,p[a[j]].id)});
            }
	//返回 
	return mind;
}
//答案排序函数
int cmp(node a,node b){
    if(a.d==b.d){
        if(a.id1==b.id1)
            return a.id2<b.id2;
        return a.id1<b.id1;
    }
    return a.d<b.d;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>p[i].x>>p[i].y;
            p[i].id=i;
        }
        sort(p,p+n,cmp1);
        double ansd=solve(0,n-1);
        sort(ans.begin(),ans.end(),cmp);
        cout<<ans[0].id1<<' '<<ans[0].id2<<'\n';
        ans.clear();
    }
	return 0;
}