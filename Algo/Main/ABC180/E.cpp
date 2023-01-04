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
struct point{
    ll x,y,z;
    point(ll xx,ll yy,ll zz):x(xx),y(yy),z(zz){  }
};
ll dist(point p1,point p2){
    return abs(p1.x-p2.x)+abs(p1.y-p2.y)+max(0ll,p2.z-p1.z);
}
int main() {
    int n;
    cin>>n;
    vector<point> vec;
    rep(i,n){
        int xx,yy,zz;
        cin>>xx>>yy>>zz;
        point el(xx,yy,zz);
        vec.emplace_back(el);
    }

    vector<vector<ll>> dp(n,vector<ll>(1<<n,INFL));
    dp[0][0]=0;
    rep(bit,1<<n)rep(i,n){
        rep(nex,n){
            if(bit&(1<<nex))continue;
            int next_bit=bit|(1<<nex);
            chmin(dp[nex][next_bit],dp[i][bit]+dist(vec[i],vec[nex]));
        }
    }
    cout<<dp[0][(1<<n)-1]<<endl;
}