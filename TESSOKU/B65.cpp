#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    //ラムダ式再帰
    int N,T;
    cin>>N>>T;
    T--;
    Graph G(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> visited(N,false);
    vector<int> ans(N,-1);
    auto dfs=[&](auto f,int v)->int{
        if(ans[v]!=-1)return ans[v];
        visited[v]=true;
        int res=0;
        for(auto u:G[v]){
            if(visited[u])continue;
            int t=f(f,u);
            res=max(res,t+1);
        }
        return ans[v]=res;
    };
    dfs(dfs,T);
    for(int i=0;i<N;i++)cout<<ans[i]<<'\n';
}