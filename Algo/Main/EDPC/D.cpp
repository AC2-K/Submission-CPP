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
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
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
int main() {
    int n,W;
    cin>>n>>W;
    vector<int> v(n),w(n);
    rep(i,n)cin>>w[i]>>v[i];
    vector<vector<ll>> dp(n+1,vector<ll>(W+1)); //dp[i][j]:=先頭i項見て、j以下となるような価値の最大値
    dp[0][0]=0;
    rep(i,n)rep(j,W+1){
        chmax(dp[i+1][j],dp[i][j]);
        if(j+w[i]>W)continue;
        chmax(dp[i+1][j+w[i]],dp[i][j]+v[i]);
    } 

    ll ans=0;
    for(int i=0;i<=W;i++){
        chmax(ans,dp[n][i]);
    }

    cout<<ans<<endl;
}