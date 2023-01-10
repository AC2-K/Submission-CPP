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
vector<int> topological_sort(vector<vector<int>>g){
    for(auto&list:g){
        sort(list.begin(),list.end());
    }
    int n=g.size();
    vector<bool> vis(n,false);
    vector<int> res;
    auto dfs=[&](auto f,int v)-> void {
        vis[v]=true;
        for(auto nex:g[v]){
            if(vis[nex])continue;
            f(f,nex);
        }
        res.push_back(v);
    };
    for(int v=0;v<n;v++){
        if(vis[v])continue;
        dfs(dfs,v);
    }
    reverse(res.begin(),res.end());
    return res;
}

int main() {
    int n,m;
    cin>>n>>m;
    graph g(n);
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
    }
    auto res=topological_sort(g);

    vector<int> dp(n);  //vをbackとする有向パスの最大長
    dp[res[0]]=0;
    for(int i=0;i<n;i++){
        int v=res[i];
        for(auto nex:g[v]){
            chmax(dp[nex],dp[v]+1);
        }
    }
    cout<<(*max_element(all(dp)))<<endl;
}