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
const int MAX_N = 60;

int T=1;
int n,m;
int l[MAX_N],r[MAX_N];
//cnt[i][j]: i个位置，提供j个因子3的方案数
ll cnt[MAX_N][MAX_N<<1];
ll single[MAX_N];

struct Group{
    int cnt;
    vector<int> intervals;
};

vector<Group> groups;
map<vector<int>,ll> dp;

void init(){
    cnt[0][0]=1;
    for(int i=0;i<50;i++){
        for(int j=0;j<=100;j++){
            if(cnt[i][j]==0)
                continue;
            cnt[i+1][j]=(cnt[i+1][j]+cnt[i][j]*6)%mod;
            if(j+1<=100)
                cnt[i+1][j+1]=(cnt[i+1][j+1]+cnt[i][j]*2)%mod;
            if(j+2<=100)
                cnt[i+1][j+2]=(cnt[i+1][j+2]+cnt[i][j]*2)%mod;
        }
    }
    for(int len=1;len<=50;len++)
        for(int c3=2;c3<=100;c3++)
            single[len]=(single[len]+cnt[len][c3])%mod;
}

ll solve(int g,vector<int> state){
    if(g==groups.size()){
        for(int i=0;i<m;i++)
            if(state[i]<2)
                return 0;
        return 1;
    }
    auto key=state;
    key.insert(key.begin(),g);
    if(dp.count(key))
        return dp[key];
    ll ans=0;
    Group &cur=groups[g];
    if(cur.intervals.empty()){
        ans=1;
        for(int i=0;i<cur.cnt;i++)
            ans=ans*10%mod;
        dp[key]=ans*solve(g+1,state)%mod;
        return dp[key];
    }
    int upper=min(100,2*cur.cnt);
    for(int total=0;total<=upper;total++){
        vector<int> new_state=state;
        for(int id:cur.intervals){
            new_state[id]+=total;
            if(new_state[id]>2)
                new_state[id]=2;
        }
        ll c=cnt[cur.cnt][total];
        if(c>0){
            ans=(ans+c*solve(g+1,new_state))%mod;
        }
    }
    dp[key]=ans;
    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
    init();
	while(cin>>n>>m){
        dp.clear();
        groups.clear();
		vector<pair<int,int>> input_intervals;
        for(int i=0;i<m;i++){
            int L,R;
            cin>>L>>R;
            input_intervals.push_back({L,R});
        }
        vector<bool> is_big(m,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                if(i==j)
                    continue;
                int li=input_intervals[i].first,ri=input_intervals[i].second;
                int lj=input_intervals[j].first,rj=input_intervals[j].second;
                if(li<=lj&&rj<=ri&&(li<lj||rj<ri)){
                    is_big[i]=true;
                    break;
                }
                if(li==lj&&ri==rj&&i>j){
                    is_big[i]=true;
                    break;
                }
            }
        }
        vector<pair<int,int>> small_intervals;
        for(int i=0;i<m;i++)
            if(!is_big[i])
                small_intervals.push_back(input_intervals[i]);
        
        m=small_intervals.size();
        vector<bool> is_isolated(m,true);
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++)
                if(i!=j){
                    int li=small_intervals[i].first,ri=small_intervals[i].second;
                    int lj=small_intervals[j].first,rj=small_intervals[j].second;
                    if(!(ri<lj||rj<li)){
                        is_isolated[i]=false;
                        break;
                    }
                }
        ll ans=1;
        vector<pair<int,int>> non_isolated;
        set<int> isolated_positions;
        for(int i=0;i<m;i++){
            if(is_isolated[i]){
                int len=small_intervals[i].second-small_intervals[i].first+1;
                ans=ans*single[len]%mod;
                for(int pos=small_intervals[i].first;pos<=small_intervals[i].second;pos++)
                    isolated_positions.insert(pos);
            }
            else{
                non_isolated.push_back(small_intervals[i]);
            }
        }
        m=non_isolated.size();
        for(int i=0;i<m;i++){
            l[i]=non_isolated[i].first;
            r[i]=non_isolated[i].second;
        }
        map<set<int>,int> group_map;
        for(int pos=1;pos<=n;pos++){
            if(isolated_positions.count(pos))
                continue;
            set<int> cover_set;
            for(int i=0;i<m;i++)
                if(l[i]<=pos&&pos<=r[i])
                    cover_set.insert(i);
            group_map[cover_set]++;
        }
        for(auto &p:group_map){
            Group g;
            g.intervals=vector<int>(p.first.begin(),p.first.end());
            g.cnt=p.second;
            groups.push_back(g);
        }
        vector<int> init_state(m,0);
        ll res=solve(0,init_state);
        ans=ans*res%mod;
        cout<<ans<<endl;
	}   
	return 0;
}