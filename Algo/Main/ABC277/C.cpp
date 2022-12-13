#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
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
void dfs(int v,map<int,vector<int>>&G,set<int>&visited){
    visited.insert(v);
    if(!G.count(v))return;
    for(auto nxt:G[v]){
        if(visited.count(nxt))continue;
        dfs(nxt,G,visited);
    }
}

int main() {
    int N;
    cin>>N;
    map<int,vector<int>> G;
    vector<int> A(N),B(N);
    rep(i,N){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        A[i]=a;
        B[i]=b;
    }
    set<int> visited;
    dfs(0,G,visited);
    int ans=0;
    for(auto v:visited)ans=max(ans,v);
    cout<<ans+1<<endl;
}