#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
template<typename T>T chmin(T &x,T &y){x=min(x,y);}
template<typename T>T chmax(T&x,T&y){x=max(x,y);}
int main() {
    //ダイクストラで頑張る...!!!
    //入力
    int N,M;
    cin>>N;
    M=N-1;
    vector<vector<P>> G(N);
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    int Q,K;
    cin>>Q>>K;
    K--;
    vector<int> X(Q),Y(Q);
    rep(i,Q)cin>>X[i]>>Y[i];

    vector<ll> cur(N,INFL);
    vector<bool> conf(N,false);
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(make_pair(0,K));//que:=(cur[i],i);
    cur[K]=0;

    while(!que.empty()){
        P T=que.top();
        que.pop();
        if(conf[T.second])continue;

        conf[T.second]=true;
        for(auto v:G[T.second]){
            ll nxt=v.first;
            ll cost=cur[T.second]+v.second;

            if(cur[nxt]<cost)continue;
            cur[nxt]=cost;
            que.push(make_pair(cost,nxt));
        }
    }
    rep(i,Q){
        cout<<cur[X[i]-1]+cur[Y[i]-1]<<endl;
    }
}