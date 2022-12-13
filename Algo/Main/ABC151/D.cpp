#include<bits/stdc++.h>
using namespace std;
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
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H){
        cin>>S[i];
    }
    int ans=0;
    rep(si,H)rep(sj,W)rep(gi,H)rep(gj,W){
        if(si==gi&&sj==gj)continue;
        if(S[si][sj]=='#'||S[gi][gj]=='#')continue;
        vector<vector<int>> dist(H,vector<int>(W,-1));
        queue<P> que;
        dist[si][sj]=0;
        que.emplace(si,sj);
        while(!que.empty()) {
            P T = que.front();
            int vi = T.first, vj = T.second;
            rep(i, 4) {
                int ni = vi + dx[i], nj = vj + dy[i];
                if (ni < 0 || nj < 0)continue;
                if (ni >= H || nj >= W)continue;
                if (dist[ni][nj] != -1)continue;
                if (S[ni][nj] == '#')continue;

                dist[ni][nj] = dist[vi][vj] + 1;
                que.emplace(ni, nj);
            }
            que.pop();
            ans=max(ans,dist[gi][gj]);
        }
    }
    cout<<ans<<endl;
}