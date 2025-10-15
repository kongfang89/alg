#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int n, m;
int L[55], R[55];

// ways[i][j] = i个位置，提供j个因子3的方案数
ll ways[55][105];

// single[len] = 长度为len的独立区间的方案数
ll single[55];

void precompute_ways() {
    memset(ways, 0, sizeof(ways));
    ways[0][0] = 1;
    
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j <= 100; j++) {
            if (ways[i][j] == 0) continue;
            ways[i+1][j] = (ways[i+1][j] + ways[i][j] * 6) % mod;
            if (j+1 <= 100)
                ways[i+1][j+1] = (ways[i+1][j+1] + ways[i][j] * 2) % mod;
            if (j+2 <= 100)
                ways[i+1][j+2] = (ways[i+1][j+2] + ways[i][j] * 2) % mod;
        }
    }
    
    // 预计算独立区间的方案数
    // 长度为len的区间，乘积mod 9 = 0，即至少2个因子3
    memset(single, 0, sizeof(single));
    for (int len = 1; len <= 50; len++) {
        for (int cnt3 = 2; cnt3 <= 100; cnt3++) {
            single[len] = (single[len] + ways[len][cnt3]) % mod;
        }
    }
}

struct Group {
    int cnt;
    vector<int> intervals;
};

vector<Group> groups;
map<vector<int>, ll> memo;

ll solve(int g, vector<int> state) {
    if (g == groups.size()) {
        for (int i = 0; i < m; i++) {
            if (state[i] < 2) return 0;
        }
        return 1;
    }
    
    auto key = state;
    key.insert(key.begin(), g);
    if (memo.count(key)) {
        return memo[key];
    }
    
    ll ans = 0;
    Group &cur = groups[g];
    
    // 关键优化：如果这个组不属于任何区间（独立位置）
    if (cur.intervals.empty()) {
        // 这些位置可以随意填，10^cnt种
        ans = 1;
        for (int i = 0; i < cur.cnt; i++) {
            ans = ans * 10 % mod;
        }
        return memo[key] = ans * solve(g + 1, state) % mod;
    }
    
    // 关键优化：计算当前组影响的区间中，最多需要多少因子3
    int max_deficit = 0;
    bool all_satisfied = true;
    for (int id : cur.intervals) {
        if (state[id] < 2) {
            all_satisfied = false;
            max_deficit = max(max_deficit, 2 - state[id]);
        }
    }
    
    // 只枚举到必要的上界
    int upper = min(100, 2 * cur.cnt);
    if (all_satisfied) {
        // 所有覆盖的区间都已满足，仍需完整枚举
        // 因为后续组可能需要这些位置
        upper = min(100, 2 * cur.cnt);
    }
    
    for (int total = 0; total <= upper; total++) {
        vector<int> new_state = state;
        for (int id : cur.intervals) {
            new_state[id] += total;
            if (new_state[id] > 2) new_state[id] = 2;
        }
        
        ll cnt = ways[cur.cnt][total];
        if (cnt > 0) {
            ans = (ans + cnt * solve(g + 1, new_state)) % mod;
        }
    }
    
    memo[key] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    
    precompute_ways();
    
    while(cin >> n >> m) {
        memo.clear();
        groups.clear();
        
        vector<pair<int,int>> raw_intervals;
        for(int i = 0; i < m; i++) {
            int l, r;
            cin >> l >> r;
            raw_intervals.push_back({l, r});
        }
        
        // 关键优化：删除冗余区间
        // 如果区间i包含区间j（i更大），则删除区间i
        vector<bool> is_redundant(raw_intervals.size(), false);
        for (int i = 0; i < (int)raw_intervals.size(); i++) {
            for (int j = 0; j < (int)raw_intervals.size(); j++) {
                if (i != j && !is_redundant[i]) {
                    int li = raw_intervals[i].first, ri = raw_intervals[i].second;
                    int lj = raw_intervals[j].first, rj = raw_intervals[j].second;
                    // i包含j（i是大区间），标记i为冗余
                    if (li <= lj && rj <= ri && (li < lj || rj < ri)) {
                        is_redundant[i] = true;
                        break;
                    }
                }
            }
        }
        
        // 只保留非冗余区间
        vector<pair<int,int>> intervals;
        for (int i = 0; i < (int)raw_intervals.size(); i++) {
            if (!is_redundant[i]) {
                intervals.push_back(raw_intervals[i]);
            }
        }
        
        // 新优化：找出独立区间（不与任何其他区间相交）
        vector<bool> is_isolated(intervals.size(), true);
        for (int i = 0; i < (int)intervals.size(); i++) {
            for (int j = 0; j < (int)intervals.size(); j++) {
                if (i != j) {
                    int li = intervals[i].first, ri = intervals[i].second;
                    int lj = intervals[j].first, rj = intervals[j].second;
                    // 判断是否相交
                    if (!(ri < lj || rj < li)) {
                        is_isolated[i] = false;
                        break;
                    }
                }
            }
        }
        
        // 计算独立区间的贡献
        ll isolated_contribution = 1;
        vector<pair<int,int>> non_isolated;
        set<int> isolated_positions; // 记录独立区间覆盖的位置
        
        for (int i = 0; i < (int)intervals.size(); i++) {
            if (is_isolated[i]) {
                int len = intervals[i].second - intervals[i].first + 1;
                isolated_contribution = isolated_contribution * single[len] % mod;
                // 记录这些位置
                for (int pos = intervals[i].first; pos <= intervals[i].second; pos++) {
                    isolated_positions.insert(pos);
                }
            } else {
                non_isolated.push_back(intervals[i]);
            }
        }
        
        // 将筛选后的区间复制到L[], R[]
        m = non_isolated.size();
        for (int i = 0; i < m; i++) {
            L[i] = non_isolated[i].first;
            R[i] = non_isolated[i].second;
        }
        
        // 按覆盖情况分组（只考虑非独立区间覆盖的位置）
        map<set<int>, int> group_map;
        for (int pos = 1; pos <= n; pos++) {
            // 跳过独立区间覆盖的位置
            if (isolated_positions.count(pos)) continue;
            
            set<int> covering;
            for (int i = 0; i < m; i++) {
                if (L[i] <= pos && pos <= R[i]) {
                    covering.insert(i);
                }
            }
            group_map[covering]++;
        }
        
        for (auto &p : group_map) {
            Group g;
            g.intervals = vector<int>(p.first.begin(), p.first.end());
            g.cnt = p.second;
            groups.push_back(g);
        }
        
        vector<int> init_state(m, 0);
        ll result = solve(0, init_state);
        result = result * isolated_contribution % mod;
        cout << result << endl;
    }
    
    return 0;
}