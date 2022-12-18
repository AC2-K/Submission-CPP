
#include <bits/stdc++.h>
using namespace std;
// cout << fixed << setprecision(10);
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
struct Edge
{
    /* data */
    int to;
    int cost;

    Edge(int a,int b):to(a),cost(b){    }
};

int main()
{
    int K;
    cin>>K;
    vector<vector<Edge>> G(K+1);
    for(int i=0;i<=K;i++){
        G[i].push_back(Edge((i+1)%K,1));
        G[i].push_back(Edge(10*i%K,0));
    }
    deque<int> que;
    que.push_back(1);
    vector<int> dist(K,INF);
    dist[1]=1;
    while(!que.empty()){
        int t=que.front();
        que.pop_front();
        for(auto e:G[t]){
            int nex=e.to;
            int c=e.cost;
            if(dist[nex]<=dist[t]+c)continue;
            dist[nex]=dist[t]+c;
            if(c==0)que.push_front(nex);
            else que.push_back(nex);
        }
    }
    cout<<dist[0]<<endl;
}