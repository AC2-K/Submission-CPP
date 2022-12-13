#include<bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N,M;
    cin>>N>>M;
    Graph G(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(v,N){
        queue<int> que;
        vector<int> dist(N,-1);
        que.push(v);
        dist[v]=0;
        //BFS
        while(!que.empty()){
            int t=que.front();que.pop();
            for(auto nex:G[t]){
                if(dist[nex]!=-1)continue;
                dist[nex]=dist[t]+1;
                que.push(nex);
            }
        }
        int ans=0;
        rep(u,N){
            if(dist[u]==2)ans++;
        }
        cout<<ans<<endl;
    }
}