#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#define rep(i, N)  for(int i=0;i<(N);i++)
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
int main() {
    int N;
    cin>>N;
    int M;
    cin>>M;
    auto getId=[&](int i,int j){
        if(i<0||j<0||i>=N||j>=N)return -1;
        return i*N+j;
    };
    //差分
    set<P> dij;
    for(int i=0;i*i<=M;i++)for(int j=0;j*j<=M;j++){
        if(i*i+j*j==M){
            dij.insert({i,j});
            dij.insert({j,i});
            dij.insert({-i,-j});
            dij.insert({-j,-i});
            dij.insert({i,-j});
            dij.insert({-i,j});
            dij.insert({j,-i});
            dij.insert({-j,i});
        }
    }
    vector<vector<int>> G(N*N);
    rep(i,N)rep(j,N){
        int id=getId(i,j);
        for(auto d:dij){
            int di=d.first,dj=d.second;
            int ni=i+di,nj=j+dj;
            
            int nxtId=getId(ni,nj);
            G[id].push_back(nxtId);
        }
    }
    vector<int> dist(N*N,-1);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto nxt:G[v]){
            if(dist[nxt]!=-1)continue;
            dist[nxt]=dist[v]+1;
            que.push(nxt);
        }
    }
    rep(i,N){
        rep(j,N){
            cout<<dist[getId(i,j)]<<' ';
        }
        cout<<'\n';
    }
}