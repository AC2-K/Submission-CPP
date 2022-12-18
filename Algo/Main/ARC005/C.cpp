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
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    int sx=-1,sy=-1,gx=-1,gy=-1;
    rep(i,H)rep(j,W){
        if(S[i][j]=='s')sx=i,sy=j;
        if(S[i][j]=='g')gx=i,gy=j;
    }
    deque<P> que;
    vector<vector<int>> dist(H,vector<int>(W,INF));
    que.emplace_back(sx,sy);
    dist[sx][sy]=0;
    
    while(!que.empty()){
        auto t=que.front();
        que.pop_front();
        int vi=t.first,vj=t.second;
        rep(i,4){
            int ni=vi+dx[i],nj=vj+dy[i];
            if(ni<0||nj<0||ni>=H||nj>=W)continue;
            if(S[ni][nj]=='#'){
                if(dist[ni][nj]<=dist[vi][vj]+1)continue;
                dist[ni][nj]=dist[vi][vj]+1;
                que.emplace_back(ni,nj);
            }else{
                if(dist[ni][nj]<=dist[vi][vj])continue;
                dist[ni][nj]=dist[vi][vj];
                que.emplace_front(ni,nj);
            }
        }
    }
    cout<<(dist[gx][gy]>2?"NO":"YES")<<endl;
}