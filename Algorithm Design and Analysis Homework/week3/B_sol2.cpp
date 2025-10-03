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
//复数 
typedef complex<double> cp;
double pi=acos(-1.0);
const int MAX_N=40010; 
const int MAX_M=160010;
/*题解：
本题使用FFT也可以通过，只需要把D题代码的ans视作二进制处理即可
https://github.com/kongfang89/alg/blob/master/Algorithm_Kongfang89/%E7%AE%97%E6%B3%95%20%E5%BF%AB%E9%80%9F%E5%82%85%E9%87%8C%E5%8F%B6%E5%8F%98%E6%8D%A2FFT.md
如果latex没有渲染，可以下载到本地浏览
*/
//输入数 
char s1[MAX_N],s2[MAX_N];
//数位长度 
int lena,lenb;
//多项式 
cp a[MAX_M],b[MAX_M];
//FFT要计算的单位根数，log_{2}(limit) 
int limit,len;
//每个单位根结束位置，输出答案 
int rev[MAX_M],ans[MAX_M];
//a是要FFT的多项式，f是(1/-1)->(FFT/IFFT)
//因为FFT和IFFT比较相似，只是IFFT需要特殊处理一下，所以写作一个函数 
void FFT(cp *a,int f){
	//先将每一项移到结束位置
	for(int i=0;i<limit;i++)
		if(i<rev[i])
			swap(a[i],a[rev[i]]);
	//从结束往开始推，i表示当前处理的项数n的一半，第一次是1，而后每次*2，最后一次是limit/2 
	for(int i=1;i<limit;i*=2){
		//计算当前的单位根w_{n}^{1}
		//w_{n}^{1}=w_{2i}^{1}=cos[(2*1*pi)/(2i)]+sin[(2*1*pi)/(2i)]i(这个i是虚数单位)=cos(pi/i)+sin(pi/i)i(这个i是虚数单位)
		cp wn(cp(cos(pi/i),f*sin(pi/i)));
		//j表示分组，也可以理解成位数（每组的起点），随着i增大，j的步长也变大 
		for(int j=0;j<limit;j+=i*2){
			//从w_{n}{0}开始，w_{n}{0}=1+0i; 
			cp w(1,0);
			//遍历前半部分即可，后半部分蝴蝶变换可以直接算出来 
			for(int k=0;k<i;k++){
				//这里的x,y就是A0(x)和w*A1(x) 
				cp x=a[j+k];
				cp y=w*a[j+k+i];
				a[j+k]=x+y;
				a[j+k+i]=x-y;
				//w的上标从0开始，要跟着k走，所以每次乘一个wn使上标+1就行 
				w*=wn;
			}
		}
	}
	//如果是IFFT，则每一项再除以limit就行
	if(f==-1){
		for(int i=0;i<limit;i++)
			a[i]/=limit;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	//输入 
	while(cin>>s1>>s2){
        //获取字符串s1,s2的长度-1，也即最后一个数的下标，前面补4个零
        lena=strlen(s1);
        lenb=strlen(s2);
        limit=1;
        len=0;
        for(int i=0;i<MAX_M;i++)
            rev[i]=ans[i]=0,a[i]=b[i]=0;
        //将两个数的倒序按位存在复数的实部中：比如123456789这个数，存在字符串中就是98765432100000......（下标由0到MAX_N-1） 
        for(int i=0;i<lena;i++)
            a[i]=(double)(s1[lena-i-1]-'0');
        for(int i=0;i<lenb;i++)
            b[i]=(double)(s2[lenb-i-1]-'0');
        //计算limit,len
        //limit:大于等于lena+lenb的第一个2的m次幂，这是为了便于FFT递归分治的实现 
        //len:log_{2}(limit)
        while(limit<lena+lenb){
            limit<<=1;
            len++;
        }
        //预处理出所有w_{n}{i}最终的位置 
        for(int i=0;i<limit;i++)
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
        //FFT:将a,b两个多项式的系数表示转为点值表示 
        FFT(a,1);
        FFT(b,1);
        //点值表示的多项式乘法：y值相乘 
        for(int i=0;i<=limit;i++)
            a[i]=a[i]*b[i];
        //IFFT:将多项式相乘结果的点值表示转为系数表示 
        FFT(a,-1);
        //将每一位进位后存到ans数组 
        for(int i=0;i<=limit;i++){
            ans[i]+=(int)(a[i].real()+0.5);
            ans[i+1]+=ans[i]/2;
            ans[i]%=2;
        }
        //数前面位为0的部分不要 
        while(limit&&!ans[limit])
            limit--;
        //输出答案 
        for(int i=limit;i>=0;i--)
            cout<<ans[i];
        cout<<'\n';
    }	
	return 0;
}