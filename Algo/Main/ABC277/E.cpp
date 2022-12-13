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
typedef pair<int, int> edge;
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    int n2=n*2; 
    vector<vector<edge>> g(n2+1);
    rep(i,m){
        int u,v,a;
        cin>>u>>v>>a; 
        if(a){
            g[u].push_back(edge(v, 1));
            g[v].push_back(edge(u, 1));
        }
        else{
            g[n+u].push_back(edge(n+v, 1));
            g[n+v].push_back(edge(n+u, 1));
        }
    }
    rep(i,k){
        int v;
        cin>>v;
        g[v].push_back(edge(v+n,0));
        g[v+n].push_back(edge(v,0));
    }

    deque<int> que;
    vector<int> dist(n2+1,INF);
    que.push_front(1);
    dist[1]=0;
    while(!que.empty()){
        int v=que.front();
        que.pop_front();
        for(auto uu:g[v]){
            int u=uu.first;
            int c=uu.second;
            if(dist[u]>dist[v]+c){
                dist[u]=dist[v]+c;
                if(c==0)que.push_front(u);
                else que.push_back(u);
            }
        }
    }
    int ans=min(dist[n],dist[n2]);
    if(ans>=INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}