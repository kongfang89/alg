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
/*题解：
设第一人到达时间为x，第二人到达时间为y，则两人相遇的条件为|x-y|<=w
其中x在[t1,t2]均匀分布，y在[s1,s2]均匀分布，则概率为满足条件的面积与总面积之比
总面积area=(t2-t1)*(s2-s1)
满足条件的面积被两条直线y=x-w和y=x+w分割成三部分：
1. y<=x-w的部分面积area1
2. x-w<y<x+w的部分面积area_meet
3. y>=x+w的部分面积area2
则area_meet=area-area1-area2
area1和area2可以通过积分计算得到
*/
int T=1;

double calc_integral(double a,double b,double c){
    if(a>=b)
        return 0;
    return (b-a)*c+(b*b-a*a)/2.0;
}

double calc(double t1,double t2,double s1,double s2,double w){
    double res=0.0;
    double start1=max(t1,s1+w);
    double end1=min(t2,s2+w);
    if(start1<end1)
        res+=calc_integral(start1,end1,-w-s1);
    double start2=max(t1,s2+w);
    double end2=t2;
    if(start2<end2)
        res+=(end2-start2)*(s2-s1);
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	cin>>T;
	for(int _=1;_<=T;_++){
        cout<<"Case #"<<_<<": ";
        double t1,t2,s1,s2,w;
        cin>>t1>>t2>>s1>>s2>>w;
        double area=(t2-t1)*(s2-s1);
        double area1=calc(t1,t2,s1,s2,w);
        double area2=calc(s1,s2,t1,t2,w);
        double meet_area=area-area1-area2;
        meet_area=max(0.0,meet_area);
        meet_area=min(area,meet_area);
        double p=meet_area/area;
        cout<<fixed<<setprecision(6)<<p<<'\n';
	}
	return 0;
}