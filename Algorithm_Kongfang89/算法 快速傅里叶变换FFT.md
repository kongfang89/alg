### 一、概念

**快速傅里叶变换(Fast Fourier Transform, FFT)**是一种加速多项式乘法的高效算法，

对于两个多项式$y_{1}=a_{0}x^{0}+a_{1}x^{1}+\dots+a_{n-1}x^{n-1},y_{2}=b_{0}x^{0}+b_{1}x^{1}+\dots+b_{n-1}x^{n-1}$​

若要计算$y1\times y2$​的结果：BF的复杂度是$O(n^{2})$，而FFT的复杂度是$O(nlogn)$​

#### 前置知识：

1. **多项式的表示法**

    形如$y=a_{0}x^{0}+a_{1}x^{1}+\dots+a_{n-1}x^{n-1}$​这样的多项式，我们有两种表示法可以唯一确定一个多项式

    - 系数表示法

        用多项式各项系数数组$\{a_{0},a_{1},\dots,a_{n-1}\}$​​表示该多项式

    - 点值表示法

        在平面直角坐标系中，多项式函数$y$​可以被$n$​个点唯一确定，代入$n$​个点的坐标$(x,y)$​求解$n$​元方程组即可，即用$\{(x_{0},f(x_{0})),(x_{1},f(x_{1})),\dots,(x_{n-1},f(x_{n-1}))\}$​​表示该多项式

2. **多项式相乘**

    - 系数表示法

        对于两个多项式各项系数数组$\{a_{0},a_{1},\dots,a_{n-1}\},\{b_{0},b_{1},\dots,b_{n-1}\}$​​​，多项式相乘需要系数逐个相乘，总共要计算$n^{2}$​​次

    - 点值表示法

        对于两个多项式：

        $\{(x_{0},f(x_{0})),(x_{1},f(x_{1})),\dots,(x_{n-1},f(x_{n-1}))\}$

        $\{(x_{0},g(x_{0})),(x_{1},g(x_{1})),\dots,(x_{n-1},g(x_{n-1}))\}$

        当对应位置取相同的$x$时，我们只需要让$y$​​​值对应相乘即可

        即$\{(x_{0},f(x_{0})g(x_{0})),(x_{1},f(x_{1})g(x_{1})),\dots,(x_{n-1},f(x_{n-1})g(x_{n-1}))\}$​，总共要计算$n$​次

    显然用点值表示法计算多项式相乘更为高效，而我们通常用系数表示法表示多项式，所以我们需要先将**系数转点值**，这里就用到了**FFT**算法，计算完后再用**IFFT**​​​​算法将**点值转系数**即可。

3. **复数**

    - 定义

        **复数**是数的概念扩展，形如$z=a+bi$​​的就是**复数**，其中$a,b$​​为实数，$a$​​是**实部**，$b$​​是**虚部**，$i$​​​​是**虚数单位**，$i^2=-1$​。若$a=0,b\neq0$，称$z$​是**纯虚数**；若$b=0$，这个复数可以看作实数；当且仅当$a=b=0$，这个复数为实数$0$​​。**复数的模**为$|z|=\sqrt{a^{2}+b^{2}}$

    - 运算法则

        设复数$z_{1}=a+bi,z_{2}=c+di$

        加法：$z_{1}+z_{2}=(a+bi)+(c+di)=(a+c)+(b+d)i$​

        减法：$z_{1}-z_{2}=(a+bi)-(c+di)=(a-c)+(b-d)i$

        乘法：$z_{1}\times z_{2}=(a+bi)\times(c+di)=(ac-bd)+(bc+ad)i$​

        除法：$z_{1}\div z_{2}=(a+bi)\div(c+di)=\frac{ac+bd}{c^{2}+d^{2}}+\frac{bc-ad}{c^{2}+d^{2}}i$​

    - 共轭复数

        $z=a+bi$​的共轭复数为$z'=a-bi$，即实部不变，虚部取反。特别地，一个复数的模为$1$时，​​该复数与其共轭复数互为**倒数**。

    - 单位根

        若复数$z=a+bi$满足$z^{n}=1$，则称$z$是$n$​次单位根。

        **如何求单位根？**

        在平面直角坐标系上，以$x$​轴为实数轴，$y$​​轴为虚数轴，将一个以原点为圆心的单位圆$n$等分，所有分界线与圆的$n$个交点都是$n$次单位根

        $n$​​等分会交出$n$​​个单位根，这里记作$w_{n}^{k}\space(k\in [0,n-1])$​​，特别地，我们规定在$(1,0)$​​点的单位根为$w_{n}^{0}$​​，其余的$w_{n}^{k}\space (k\in[1,n-1])$​​按逆时针顺序编号。

        因为是$n$​等分，​分出来的$n$个扇形的圆心角都是$\frac{2\pi}{n}$

        所以有$w_{n}^{k}=cos\frac{2k\pi}{n}+sin\frac{2k\pi}{n}i$

        **单位根性质**

        1. $w_{n}^{i}\neq w_{n}^{j},\forall i\neq j\space(i,j<n)$​​

        2. $w_{2n}^{2k}=w_{n}^{k}$​ （消去引理）

            证明：

            - 几何：把单位圆$n$​等分的第$k$​个点和把单位圆$2n$​等分的第$2k$​个点是同一个
            - 数学：$w_{2n}^{2k}=cos\frac{4k\pi}{2n}+sin\frac{4k\pi}{2n}i=cos\frac{2k\pi}{n}+sin\frac{2k\pi}{n}i=w_{n}^{k}$

        3. $w_{n}^{k+\frac{n}{2}}=-w_{n}^{k}$​ 

            即转半圈$180$度取反

        4. $w_{n}^{0}=w_{n}^{n}=1$ （周期性）​

        5. $w_{n}^{a}\times w_{n}^{b}=w_{n}^{a+b}$​​​

            证明：

            $\begin{align} w_{n}^{a}\times w_{n}^{b}&=(cos\frac{2a\pi}{n}+sin\frac{2a\pi}{n}i)\times(cos\frac{2b\pi}{n}+sin\frac{2b\pi}{n}i)\\&=(cos\frac{2a\pi}{n}cos\frac{2b\pi}{n}-sin\frac{2a\pi}{n}sin\frac{2b\pi}{n})+(sin\frac{2a\pi}{n}cos\frac{2b\pi}{n}+cos\frac{2a\pi}{n}sin\frac{2b\pi}{n})i\\&=cos(\frac{2a\pi}{n}+\frac{2b\pi}{n})+sin(\frac{2a\pi}{n}+\frac{2b\pi}{n})i\\&=w_{n}^{a+b} \end{align}$​

        

### 二、算法实现

#### 离散傅里叶变换(DFT)

对于多项式的系数转点值方法，朴素方法是取$n$​个$x$​代入，复杂度是$O(n^{2})$​，傅里叶选取一些特殊点代入，即$n$​个单位根$\{w_{n}^{1},w_{n}^{2},\dots,w_{n}^{n-1}\}$​，这种取值代入得到的点值表示就是DFT，但复杂度没有优化，所以我们需要FFT。

#### 快速傅里叶变换(FFT)

FFT是系数转点值

对于多项式$A(x)=a_{0}x^{0}+a_{1}x^{1}+\dots+a_{n-1}x^{n-1}$​​，将其按次幂的奇偶分为两部分

$A(x)=a_{0}x^{0}+a_{2}x^{2}+\dots+a_{n-2}x^{n-2}+x(a_{1}x^{0}+a_{3}x^{2}+\dots+a_{n-1}x^{n-2})$​​

令$A_{0}(x)=a_{0}x^{0}+a_{2}x^{1}+\dots+a_{n-2}x^{\frac{n}{2}-1},A_{1}(x)=a_{1}x^{0}+a_{3}x^{1}+\dots+a_{n-1}x^{\frac{n}{2}-1}$

则$A(x)=A_{0}(x^{2})+x\times A_{1}(x^{2})$

代入$n$​次单位根$x=w_{n}^{k}$​

$A(w_{n}^{k})=A_{0}(w_{n}^{2k})+w_{n}^{k}\times A_{1}(w_{n}^{2k})=A_{0}(w_{\frac{n}{2}}^{k})+w_{n}^{k}\times A_{1}(w_{\frac{n}{2}}^{k})$

$A(w_{n}^{k+\frac{n}{2}})=A_{0}(w_{n}^{2k+n})+w_{n}^{k+\frac{n}{2}}\times A_{1}(w_{n}^{2k+n})=A_{0}(w_{\frac{n}{2}}^{k})-w_{n}^{k}\times A_{1}(w_{\frac{n}{2}}^{k})$​

因此，我们发现只要有$A_{0}(w_{\frac{n}{2}}^{k}),A_{1}(w_{\frac{n}{2}}^{k})$​的值，即可知道$A(w_{n}^{k}),A(w_{n}^{k+\frac{n}{2}})$​的值

也即计算出$A_{1}(x),A_{2}(x)$​​在$\{w_{\frac{n}{2}}^{0},w_{\frac{n}{2}}^{1},\dots,w_{\frac{n}{2}}^{\frac{n}{2}-1}\}$​​的点值表示

即可$O(n)$​​算出$A(x)$​​在$\{w_{n}^{0},w_{n}^{1},\dots,w_{n}^{n-1}\}$​的点值表示

由于$A_{1}(x),A_{2}(x)$​都是$A(x)$​的子问题，不断递归分治到$n=1$​即可计算出$A(x)$​的点值表示，$n=1$​时$w_{n}^{k}=1$​

**注：**每次递归都是把$n$​分为两份，所以一开始的$n$​得是$2^{m}$​才便于计算，如果不够，高位补$0$​补到够就行。

#### 快速傅里叶逆变换(IFFT)

IFFT是点值转系数

设$\{y_{0},y_{1},\dots,y_{n-1}\}$为多项式$A(x)=a_{0}x^{0}+a_{1}x^{1}+\dots+a_{n-1}x^{n-1}$的离散傅里叶变换

设多项式$B(x)=y_{0}x^{0}+y_{1}x^{1}+\dots+y_{n-1}x^{n-1}$

将离散傅里叶变换的$n$个单位根$\{w_{n}^{0},w_{n}^{1},\dots,w_{n}^{n-1}\}$的倒数$\{w_{n}^{0},w_{n}^{-1},\dots,w_{n}^{1-n}\}$代入$B(x)$

**注：**单位根是复数，所以单位根的倒数就是复数的倒数，也即复数的共轭复数

得到$\{z_{0},z_{1},\dots,z_{n-1}\}$

$\large \begin{align} z_{k}&=\sum_{i=0}^{n-1}y_{i}(w_{n}^{-k})^{i}\\&=\sum_{i=0}^{n-1}(\sum_{j=0}^{n-1}a_{j}(w_{n}^{i})^{j})(w_{n}^{-k})^{i}\\&=\sum_{j=0}^{n-1}a_{j}(\sum_{i=0}^{n-1}(w_{n}^{i})^{j-k}) \end{align}$

若$j-k=0$

$\sum_{i=0}^{n-1}(w_{n}^{i})^{j-k}=\sum_{i=0}^{n-1}1=n$

若$j-k\neq0$

$\begin{align} \sum_{i=0}^{n-1}(w_{n}^{i})^{j-k}&=\sum_{i=0}^{n-1}(w_{n}^{j-k})^{i}\\&=\frac{1-(w_{n}^{n})^{j-k}}{1-w_{n}^{j-k}}\\&=\frac{1-1}{1-w_{n}^{j-k}}\\&=0 \end{align}$

$\therefore z_{k}=na_{k}$

$\therefore a_{k}=\frac{z_{k}}{n}$

#### FFT的递归优化

FFT计算时需要不断分组系数，以$8$个单位根系数为例，每次分组结果如下：

$sta:w_{n}^{0}\space w_{n}^{1}\space w_{n}^{2}\space w_{n}^{3}\space w_{n}^{4}\space w_{n}^{5}\space w_{n}^{6}\space w_{n}^{7}$

$1th:w_{n}^{0}\space w_{n}^{2}\space w_{n}^{4}\space w_{n}^{6},w_{n}^{1}\space w_{n}^{3}\space w_{n}^{5}\space w_{n}^{7}$

$2th:w_{n}^{0}\space w_{n}^{4},w_{n}^{2}\space w_{n}^{6},w_{n}^{1}\space w_{n}^{5},w_{n}^{3}\space w_{n}^{7}$

$3th:w_{n}^{0},w_{n}^{4},w_{n}^{2},w_{n}^{6},w_{n}^{1},w_{n}^{5},w_{n}^{3},w_{n}^{7}$

可以看出一个规律，每个数的初始位置的二进制表示和结束位置的二进制表示是相反的

如$5$开始在$101$，取反$101$还是在$5$；如$4$开始在$100$，取反$001$在$1$

基于此，我们先将结束的序列求出来，然后向上求出点值表示即可。

### 三、代码

```c++
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
const int MAX_N=1000010; 
const int MAX_M=4000010;
//输入数 
char s1[MAX_N],s2[MAX_N];
//数位长度 
int lena,lenb;
//多项式 
cp a[MAX_M],b[MAX_M];
//FFT要计算的单位根数，log_{2}(limit) 
int limit=1,len;
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
	cin>>s1>>s2;
	//获取字符串s1,s2的长度
	lena=strlen(s1);
	lenb=strlen(s2);
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
		ans[i+1]+=ans[i]/10;
		ans[i]%=10;
	}
	//数前面位为0的部分不要 
	while(limit&&!ans[limit])
		limit--;
	//输出答案 
	for(int i=limit;i>=0;i--)
		cout<<ans[i];
	cout<<'\n';
	return 0;
}
```

