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
    int CH,CW,DH,DW;
    cin>>H>>W>>CH>>CW>>DH>>DW;
    CH--;
    CW--;
    DH--;
    DW--;
    vector<string> S(H);
    rep(i,H){
        cin>>S[i];
    }
    deque<P> que;
    vector<vector<int>> dist(H,vector<int>(W,INF));
    que.emplace_front(CH,CW);
    dist[CH][CW]=0;
    while(!que.empty()){
        auto v=que.front();
        que.pop_front();
        int vi=v.first,vj=v.second;
        rep(i,4){
            int ni=vi+dx[i],nj=vj+dy[i];
            if(ni<0||nj<0||ni>=H||nj>=W)continue;
            if(S[ni][nj]=='#')continue;
            if(dist[ni][nj]>dist[vi][vj]){
                dist[ni][nj]=dist[vi][vj];
                que.emplace_front(ni,nj);
            }
        }
        for(int di=-2;di<=2;di++)for(int dj=-2;dj<=2;dj++){
            if(di==0&&dj==0)continue;
            int ni=vi+di,nj=vj+dj;
            if(ni<0||nj<0||ni>=H||nj>=W)continue;
            if(S[ni][nj]=='#')continue;
            if(dist[ni][nj]>dist[vi][vj]+1){
                dist[ni][nj]=dist[vi][vj]+1;
                que.emplace_back(ni,nj);
            }
        }
    }
    cout<<(dist[DH][DW]>=INF?-1:dist[DH][DW])<<endl;
}