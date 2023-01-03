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
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    scanf("%d",&n);
    graph g(n);
    rep(i,n-1){
        int s,t;
        scanf("%d %d",&s,&t);
        s--;
        t--;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    int now_R=1;    //葉の区間を決めておく。
    vector<P> ans(n);
    auto dfs=[&](auto f,int v,int par=-1)-> void {
        if(g[v].size()==1&&g[v][0]==par){
            ans[v]=P(now_R,now_R);
            now_R++;
        }else{
            int l=INF;
            int r=-INF;
            for(auto nex:g[v]){
                if(nex==par)continue;
                f(f,nex,v);
                chmin(l,ans[nex].first);
                chmax(r,ans[nex].second);
            }
            ans[v]=P(l,r);
        }
    };
    dfs(dfs,0);
    rep(v,n){
        printf("%d %d\n",ans[v].first,ans[v].second);
    }
}