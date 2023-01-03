#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}

class DSU
{
private:
    vector<int> par, rank, siz;
    int N;

public:
    DSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}

    int root(int x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(int x, int y)
    {
        return root(x) == root(y);
    }

    bool merge(int x, int y)
    {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;

        if (rank[rx] < rank[ry])
            swap(rx, ry);
        par[ry] = rx; 
        
        siz[rx] += siz[ry];
        return true;
    }

    int size(int x)
    {
        return siz[root(x)];
    }
    int connect()
    {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (root(i) == i)
                cnt++;
        return cnt;
    }
};
struct edge{
    int v1;
    int v2;
    edge(int a,int b):v1(a),v2(b){  };
};
int main() {
    int n,m,e;
    cin>>n>>m>>e;
    vector<edge> edges;
    rep(i,e){
        int s,t;
        cin>>s>>t;
        s--;
        t--;
        edges.push_back(edge(s,t));
    }
    int q;
    cin>>q;
    vector<int> queries;
    vector<bool> cut(e,false);
    rep(i,q){
        int x;
        cin>>x;
        x--;
        queries.push_back(x);
        cut[x]=true;
    }

    reverse(all(queries));
    DSU dsu(n+m);
    rep(i,e){
        if(cut[i])continue;
        dsu.merge(edges[i].v1,edges[i].v2);
    }
    for(int i=n;i+1<n+m;i++){
        dsu.merge(i,i+1);
    }
    vector<int> answers;
    rep(i,q){
        answers.push_back(dsu.size(n)-m);
        int x=queries[i];
        dsu.merge(edges[x].v1,edges[x].v2);
    }
    reverse(all(answers));
    for(auto a:answers)cout<<a<<endl;
}