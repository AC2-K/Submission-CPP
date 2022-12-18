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
int main() {
    int n;
    cin>>n;
    DSU dsu(n);
    vector<int> x(n),c(n);
    for(auto&xx:x)cin>>xx,xx--;
    for(auto&cc:c)cin>>cc;
    ll ans=0;
    rep(i,n){
        if(!dsu.same(i,x[i])){
            dsu.merge(i,x[i]);
            continue;
        }
        int cur=c[i],v=x[i];
        while(v!=i){
            chmin(cur,c[v]);
            v=x[v];
        }
        ans+=cur;
    }
    cout<<ans<<endl;
}