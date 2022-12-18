#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    ll n,m;
    cin>>n>>m;
    Graph g(n);
    rep(i,m){
        int s,t;
        cin>>s>>t;
        s--;
        t--;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    vector<int> color(n,-1);
    bool ok=true;
    auto dfs=[&](auto f,int v)-> P {
        P ret=make_pair(0,0);
        if(color[v]==0)ret.first++;
        else ret.second++;
        for(auto nex:g[v]){
            if(color[nex]==color[v]){
                return P(-1,-1);
            }else if(color[nex]!=-1){
                continue;
            }
            color[nex]=1-color[v];
            auto get=f(f,nex);
            if(get.first==-1)return P(-1,-1);
            else{
                ret.first+=get.first;
                ret.second+=get.second;
            }
        }
        return ret;
    };

    ll ans=n*(n-1)/2-m;
    rep(i,n){
        if(color[i]!=-1)continue;
        color[i]=0;
        auto get=dfs(dfs,i);
        if(get.first==-1){
            cout<<0<<endl;
            return 0;
        }
        ll W=get.first;
        ll B=get.second;
        ans-=W*(W-1)/2;
        ans-=B*(B-1)/2;
    }
    
    cout<<ans<<endl;
}