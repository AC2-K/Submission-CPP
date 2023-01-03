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
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
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
    assert(1==1);
    int n,q;
    cin>>n>>q;
    vector<int> x(n);
    rep(i,n)cin>>x[i];
    graph g(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<multiset<int>> SubTree(n);    //上位20個もっとけばいい
    auto dfs=[&](auto f,int v,int par=-1)-> void {
        SubTree[v].insert(x[v]);
        if(g[v].size()==1&&g[v][0]==par)return; //葉なら放置

        for(auto nex:g[v]){
            if(nex==par)continue;
            f(f,nex,v);
            for(auto el:SubTree[nex]){
                 SubTree[v].insert(el);
            }
        }
        while(SubTree[v].size()>20){
            SubTree[v].erase(SubTree[v].find(*SubTree[v].begin()));
        }
    };
    dfs(dfs,0);
    while(q--){
        int v,k;
        cin>>v>>k;
        v--;
        auto itr=SubTree[v].end();
        rep(i,k){
            itr--;
        }
        cout<<(*itr)<<endl;
    }
}