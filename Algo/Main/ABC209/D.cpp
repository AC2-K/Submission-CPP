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
    int n,q;
    cin>>n>>q;
    Graph g(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n,INF);
    queue<int> que;
    que.push(0);
    dist[0]=0;
    while(!que.empty()){
        int v=que.front();que.pop();
        for(auto nex:g[v]){
            if(dist[nex]<INF)continue;
            dist[nex]=dist[v]+1;
            que.push(nex);
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(dist[x]%2==dist[y]%2){
            cout<<"Town"<<endl;
        }else{
            cout<<"Road"<<endl;
        }
    }
}