#include <bits/stdc++.h>
#define INF 1e18
#define LINF LLONG_MAX 
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int mod = 1e9+7;
//const int mod = 998244353;
const int MAX_N = 1010;
const double eps=1e-9;

int T=1;

struct Line{
	double a,b,c;
};

pair<double, double> intersect(Line l1,Line l2){
	double det=l1.a*l2.b-l1.b*l2.a;
	if(fabs(det)<eps)
		return {INF,INF};
	double x=(l1.c*l2.b-l1.b*l2.c)/det;
	double y=(l1.a*l2.c-l1.c*l2.a)/det;
	return {x,y};
}

bool check(double x,double y,vector<Line>& lines) {
	for(auto& l:lines)
		if(l.a*x+l.b*y>l.c+eps)
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int n;
	cin>>n;
	vector<Line> lines;
	for(int i=0;i<n;i++){
		double a,b,c;
		cin>>a>>b>>c;
		lines.push_back({a,b,c});
	}
	lines.push_back({-1,0,0});
	lines.push_back({0,-1,0});
	int m=lines.size();
	vector<pair<double,double>> v;
	for(int i=0;i<m;i++){
		for(int j=i+1;j<m;j++){
			auto [x,y]=intersect(lines[i],lines[j]);
			if(x<INF-1&&y<INF-1)
				if(x>-eps&&y>-eps&&check(x,y,lines))
					v.push_back({x,y});
		}
	}
	if(v.empty()){
		cout<<"Not Found\n";
		return 0;
	}
	double ans=INF;
	for(auto [x,y]:v)
		ans=min(ans,x+y);
	if(ans>=INF-1){
		cout<<"Not Found\n";
	}
	else{
		cout<<(ll)ans<<endl;
	}
	return 0;
}
