#include <bits/stdc++.h>
using namespace std;
typedef std::vector<int> BigBinary;
const int MAX_N=100010;
char x[MAX_N],y[MAX_N];
vector<int> a,b;

vector<int> add_or_minus(const vector<int> &a,const vector<int> &b,int flag){
	vector<int> c(a);
	for(int i=0;i<b.size();i++)
		c[i]+=b[i]*flag;
	return c;
}

vector<int> mul(const vector<int> &a,const vector<int> &b){
	vector<int> c;
	c.resize(a.size()*b.size()+1);
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++)
			c[i+j]+=a[i]*b[j];
	return c;
}

void mul_n2(vector<int> &a,int n2){
	int len=a.size();
	a.resize(len+n2);
	for(int i=a.size()-1,j=len-1;j>=0;i--,j--)
		a[i]=a[j];
	for(int i=n2-1;i>=0;i--)
		a[i]=0;
}

vector<int> binary_mul(const vector<int> &a,const vector<int> &b){
	if(a.size()<32)
		return mul(a,b);
	int n2=a.size()>>1;
	vector<int> A(a.begin()+n2,a.end());
	vector<int> B(a.begin(),a.begin()+n2);
	vector<int> C(b.begin()+n2,b.end());
	vector<int> D(b.begin(),b.begin()+n2);
	vector<int> AC=binary_mul(A,C);
	vector<int> BD=binary_mul(B,D);
	vector<int> t=add_or_minus(add_or_minus(binary_mul(add_or_minus(A,B,1),add_or_minus(C,D,1)),AC,-1),BD,-1);
	mul_n2(AC,n2<<1);
	mul_n2(t,n2);
	return add_or_minus(add_or_minus(AC,t,1),BD,1);
}

int main(){
	while(scanf("%s",x)!=EOF){
		scanf("%s",y);
		a.clear();
		b.clear();
		for(int i=strlen(x)-1;i>=0;i--)
			a.push_back(x[i]-'0');
		for(int i=strlen(y)-1;i>=0;i--)
			b.push_back(y[i]-'0');
		if(a.size()<b.size())
			a.resize(b.size(),0);
		else
			b.resize(a.size(),0);
		vector<int> ans=binary_mul(a,b);
		while(!ans.empty()&&ans.back()==0)
			ans.pop_back();
		int flag=0;
		for(int i=0;i<ans.size();i++){
			ans[i]+=flag;
			flag=ans[i]>>1;
			ans[i]&=1;
		}
		for(;flag;flag>>=1)
			ans.push_back(flag&1);
		for(int i=ans.size()-1;i>=0;i--)
			printf("%d",ans[i]);
		if(ans.empty())
			printf("0");
		printf("\n");
	}
	return 0;
}