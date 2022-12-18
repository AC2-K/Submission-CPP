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
    int n,m;
    cin>>n>>m;
    Graph g(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
    }
    int s,t;
    cin>>s>>t;
    s--;
    t--;
    queue<P> que;
    vector<vector<int>> dist(n,vector<int>(3,-1));
    que.emplace(s,0);
    dist[s][0]=0;
    while(!que.empty()){
        auto ff=que.front();
        
        int v=ff.first;
        int jamp=ff.second;
        
        que.pop();
        int jamp2=(jamp+1)%3;
        for(auto nex:g[v]){
            if(dist[nex][jamp2]!=-1)continue;
            if(jamp2==0)dist[nex][jamp2]=dist[v][jamp]+1;
            else dist[nex][jamp2]=dist[v][jamp];
            que.emplace(nex,jamp2);
        }
    }
    cout<<dist[t][0]<<endl;
}