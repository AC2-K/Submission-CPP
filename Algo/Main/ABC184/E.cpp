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
    int H,W;
    cin>>H>>W;
    vector<vector<P>> tel(26);
    vector<string> S(H);
    int si,sj;
    int gi,gj;
    rep(i,H){
        cin>>S[i];
        rep(j,W){
            if(S[i][j]=='S')si=i,sj=j;
            else if(S[i][j]=='G')gi=i,gj=j;
            else if(S[i][j]!='#'&&S[i][j]!='.'){
                tel[S[i][j]-'a'].emplace_back(i,j);
            }
        }
    }
    queue<P> que;
    vector<vector<int>> dist(H,vector<int>(W,-1));
    dist[si][sj]=0;
    que.emplace(si,sj);
    while(!que.empty()){
        auto t=que.front();que.pop();
        int vi=t.first,vj=t.second;
        rep(i,4){
            int ni=vi+dx[i];
            int nj=vj+dy[i];
            if(ni<0||nj<0||ni>=H||nj>=W)continue;
            if(dist[ni][nj]!=-1)continue;
            if(S[ni][nj]=='#')continue;
            dist[ni][nj]=dist[vi][vj]+1;
            que.emplace(ni,nj);
        }
        if('a'<=S[vi][vj]&&S[vi][vj]<='z'){
            int id=S[vi][vj]-'a';
            for(auto nn:tel[id]){
                int ni=nn.first,nj=nn.second;
                if(dist[ni][nj]!=-1)continue;
                dist[ni][nj]=dist[vi][vj]+1;
                que.emplace(ni,nj);
            }
            tel[id].clear();
        }
    }
    cout<<dist[gi][gj]<<endl;
}