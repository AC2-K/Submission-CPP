#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
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
    int N;
    cin>>N;
    Graph G(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,N){
        sort(all(G[i]));
    }
    vector<bool> vis(N,false);
    vector<int> ans;
    auto dfs=[&](auto f,int v,int pre=-1)-> void {
        ans.push_back(v);
        for(auto nex:G[v])if(nex!=pre){
            f(f,nex,v);
            ans.push_back(v);
        }
    };
    dfs(dfs,0);
    for(auto a:ans)cout<<a+1<<' ';
    cout<<endl;
}