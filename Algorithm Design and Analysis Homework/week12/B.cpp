#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e18;
const int MAXN = 100000 + 5;

long long dp[21][MAXN];
int a[MAXN];
long long freq[MAXN];
long long curCost = 0;
int curL = 1, curR = 0;    // 当前有效范围为空

// 将值 x 加入当前区间
inline void add(int x) {
    curCost += freq[x];
    freq[x]++;
}

// 将值 x 从当前区间移除
inline void remove_(int x) {
    freq[x]--;
    curCost -= freq[x];
}

// 调整区间到 [l, r]
inline void moveTo(int l, int r) {
    while (curL > l) add(a[--curL]);
    while (curR < r) add(a[++curR]);
    while (curL < l) remove_(a[curL++]);
    while (curR > r) remove_(a[curR--]);
}

// 分治优化求 dp[t][L..R]
void solve(int t, int L, int R, int optL, int optR) {
    if (L > R) return;
    int mid = (L + R) >> 1;

    long long bestVal = INF;
    int bestPos = -1;

    int start = min(mid - 1, optR);

    // 枚举断点 j，区间为 (j+1 .. mid)
    for (int j = optL; j <= start; j++) {
        moveTo(j + 1, mid);
        long long val = dp[t - 1][j] + curCost;
        if (val < bestVal) {
            bestVal = val;
            bestPos = j;
        }
    }

    dp[t][mid] = bestVal;

    solve(t, L, mid - 1, optL, bestPos);
    solve(t, mid + 1, R, bestPos, optR);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 初始化 DP
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INF;

    dp[0][0] = 0;

    for (int t = 1; t <= k; t++) {
        // 清空频率数组和代价
        memset(freq, 0, sizeof(long long) * (n + 2));
        curL = 1;
        curR = 0;
        curCost = 0;

        solve(t, 1, n, 0, n - 1);
    }

    cout << dp[k][n] << "\n";
    return 0;
}
