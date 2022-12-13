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
    rep(_,M){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> dist(N,-1);
    vector<ll> cnt(N);
    queue<int> que;
    que.push(0);
    dist[0]=0;
    cnt[0]=1;
    while(!que.empty()){
        int t=que.front();que.pop();
        for(auto nex:G[t]){
            if(dist[nex]==-1){
                dist[nex]=dist[t]+1;
                cnt[nex]=cnt[t];
                cnt[nex]%=MOD;
                que.push(nex);
            }
            else if(dist[nex]==dist[t]+1){
                cnt[nex]+=cnt[t];
                cnt[nex]%=MOD;
            }
        }
    }
    cout<<cnt[N-1]<<endl;
}