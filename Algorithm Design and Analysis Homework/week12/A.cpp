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
    if (start2<end2)
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