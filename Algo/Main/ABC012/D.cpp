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
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> dist(n,vector<ll>(n,INFL));
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        dist[a][b]=c;
        dist[b][a]=c;
    }
    rep(i,n)dist[i][i]=0;
    rep(k,n)rep(i,n)rep(j,n){
        chmin(dist[i][j],dist[i][k]+dist[k][j]);
    }
    ll ans=INFL;
    rep(i,n){
        ll maxdist=0;
        rep(j,n){
            if(i==j)continue;
            chmax(maxdist,dist[i][j]);
        }
        chmin(ans,maxdist);
    }
    cout<<ans<<endl;
}