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
    int n,x;
    cin>>n>>x;
    Graph g(n);
    x--;
    vector<int> know(n,false);
    rep(i,n){
        int a;
        cin>>a;
        a--;
        g[i].push_back(a);
    }
    auto dfs=[&](auto f,int v)-> void {
        know[v]=true;
        for(auto nex:g[v]){
            if(know[nex])continue;
            f(f,nex);
        }
    };
    dfs(dfs,x);
    int cnt=0;
    for(auto k:know)if(k)cnt++;
    cout<<cnt<<endl;
}