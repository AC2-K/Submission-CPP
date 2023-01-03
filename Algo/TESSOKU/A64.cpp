#include<iostream>
#include<vector>
#include<queue>
#define rep(i,N) for(int i=0;i<(N);i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
template<typename T>T chmin(T &x,T &y){x=min(x,y);}
template<typename T>T chmax(T&x,T&y){x=max(x,y);}
int main() {
    //ダイクストラ法
    int N,M;
    cin>>N>>M;
    vector<vector<P>> G(N);

    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    vector<int> cur(N,INF);
    vector<bool> conf(N,false);
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(make_pair(0,0));//que:=(cur[i],i);
    cur[0]=0;

    while(!que.empty()){
        P T=que.top();
        que.pop();
        if(conf[T.second])continue;

        conf[T.second]=true;
        for(auto v:G[T.second]){
            int nxt=v.first;
            int cost=cur[T.second]+v.second;

            if(cur[nxt]<cost)continue;
            cur[nxt]=cost;
            que.push(make_pair(cost,nxt));
        }
    }
    rep(V,N){
        if(cur[V]>=INF)cout<<-1<<endl;
        else cout<<cur[V]<<endl;
    }
}