#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
    int N;
    cin>>N;
    Graph G(N+1);
    vector<ll> cost(N+1);
    for(int i=1;i<=N;i++){
        cin>>cost[i];

        int K;
        cin>>K;
        rep(j,K){
            int a;
            cin>>a;
            G[i].push_back(a);
        }
    }

    queue<int> que;
    vector<bool> visited(N+1,false);
    que.push(N);
    while(!que.empty()){
        int t=que.front();
        que.pop();
        visited[t]=true;
        for(auto prev:G[t]){
            if(visited[prev])continue;
            que.push(prev);
        }
    }
    ll ans=0;
    for(int i=1;i<=N;i++)if(visited[i])ans+=cost[i];
    cout<<ans<<endl;
}