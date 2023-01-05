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
    graph g(n);
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> subsize(n);    //subtree[v]:=vの部分木のサイズ
    //部分木をDFSで求めておく
    auto dfs=[&](auto f,int v,int par=-1)-> void {
        subsize[v]=1;
        if(g[v].size()==1&&g[v][0]==par)return; //葉ならすることはない。
        for(auto nex:g[v]){
            if(nex==par)continue;
            f(f,nex,v); //nexについて更新
            subsize[v]+=subsize[nex];   //加算していく
        }
        return;
    };
    dfs(dfs,0);

    //木DPする
    vector<ll> dp(n);  //dp[v]:=\sum dist(v,i)
    //dp[r]を計算する
    const int r=0;  //根
    vector<ll> from_root(n);
    from_root[r]=0;
    auto rec=[&](auto f,int v,int par=-1)-> void {
        for(auto nex:g[v]){
            if(nex==par)continue;

            from_root[nex]=from_root[v]+1;
            f(f,nex,v);
        }
    };
    rec(rec,0);
    for(auto f:from_root){
        dp[r]+=f;
    }

    //遷移:
    //頂点vと、vの親pについてdp[v]=dp[p]-(subsize[v])+(n-subsize[v])=dp[p]+n-2*subsize[v];
    vector<bool> vis(n,false);
    auto dp_rec=[&](auto f,int v,int p)-> void {
        dp[v]=dp[p]+n-2*subsize[v];
        for(auto nex:g[v]){
            if(nex==p)continue;
            f(f,nex,v);
        }
    };
    for(auto ch0:g[r]){
        dp_rec(dp_rec,ch0,r);
    }
    for(auto d:dp)cout<<d<<'\n';
}