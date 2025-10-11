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
int q;

int main(){
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	// cin>>T;
	while(T--){
		cin>>q;
        vector<int> next(q+1);
        next[0]=-1;
        for(int i=1;i<=q;i++){
            int op;
            cin>>op;
            if(op==1){
                int x;
                cin>>x;
                next[i]=next[x];
                next[x]=i;
            }
            else{
                int x,y;
                cin>>x>>y;
                int tx=x,ty=y;
                ll sx=0,sy=0;
                while(1){
                    if(next[tx]!=-1){
                        tx=next[tx];
                        if(tx==y){
                            cout<<sx<<'\n';
                            next[x]=y;
                            break;
                        }
                        else{
                            sx+=tx;
                        }
                    }
                    if(next[ty]!=-1){
                        ty=next[ty];
                        if(ty==x){
                            cout<<sy<<'\n';
                            next[y]=x;
                            break;
                        }
                        else{
                            sy+=ty;
                        }
                    }
                }
            }
        }
	}
	return 0;
}