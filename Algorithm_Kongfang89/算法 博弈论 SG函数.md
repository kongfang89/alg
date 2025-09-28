### 一、概念

 1. 组合游戏 *(Impartial Combinatorial Games, ICG)*

	- Alice Bob玩
	- 轮流进行规定的合法操作
	- 对于任何局面，合法的操作仅仅取决于这个局面，与选手无关
	- 若无法继续操作，当前选手判负

 2. 必胜态 *(N-position)* 和 必败态 *(P-position)*

	- 必胜态：当前玩家必胜的状态
	- 必败态：当前玩家必败的状态

	##### 性质

	1. 所有结束点都是必败态
	2. 从必胜态操作，至少有一种方法可以转移到必败态
	3. 从必败态操作，无论如何只能进入必胜态

### 二、SG定理

游戏和的**SG函数**等于各个游戏**SG函数的Nim和**，以此可将每个子游戏分而治之，从而简化问题。

### 三、SG函数

##### 定义：

$mex(minimal \space excludant)$运算，$mex\{A\}$表示集合$A$中最小的不属于这个集合的非负整数

例如：$mex\{0,1,3,4\}=2,mex\{1,3,4\}=0,mex\{\}=0$ 

---

对于任意状态$x$，定义$SG(X)=mex(S)$，其中$S$表示$x$的后继状态的$SG$函数值集合。

例如：$x$可以转移到$a,b,c$三个状态，则$SG(X)=mex\{SG(a),SG(b),SG(c)\}$

以此，集合$S$的最终状态一定是$\varnothing$，即$SG$函数的最终状态$t$的$SG(t)=0$，此时$t$为必败态。

### 四、代码模板

```c++
//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
int f[N],SG[MAX_N],S[MAX_N];

void getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));
    //因为SG[0]始终等于0，所以i从1开始
    for(i=1;i<=n;i++){
        //每一次都要将上一状态的后继集合重置
        memset(S,0,sizeof(S));
        //遍历所有后继状态，将后继状态的SG函数值进行标记
        for(j=0;f[j]<=i&&j<=N;j++)
            S[SG[i-f[j]]]=1;
        //查询当前后继状态SG值中最小的非零值，即查询后继状态SG值的mex值
        for(j=0;;j++){
            if(!S[j]){   
                SG[i]=j;
                break;
        	}
        }
    }
}
```

### 五、题单

1. 洛谷

- [P2197](https://www.luogu.com.cn/problem/P2197) Nim取子：SG定理
- [P1288](https://www.luogu.com.cn/problem/P1288) 取数游戏
- [P1290](https://www.luogu.com.cn/problem/P1290) 欧几里得游戏：SG定理
- [P1247](https://www.luogu.com.cn/problem/P1247) 取火柴游戏：SG定理
- [P2252](https://www.luogu.com.cn/problem/P2252) 威佐夫博弈

