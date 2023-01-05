#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    graph g(n);
    rep(i,n-1){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dp(n+1,inf);   //dp[l]:=長さlのLISを作るとき、末尾の最小値
    vector<int> ans(n);   //ans[v]:=0-vパス上のLIS
    
    auto dfs=[&](auto f,int v,int par=-1)-> void {
        auto it=lower_bound(all(dp),a[v]);  //a[v]
        ll pre=*it;
        *it=a[v];
        ans[v]=lower_bound(all(dp),inf)-dp.begin();
        for(auto nex:g[v]){
            if(nex==par)continue;
            f(f,nex,v);
        }
        *it=pre;
    };
    dfs(dfs,0);

    rep(v,n)cout<<ans[v]<<'\n';
}