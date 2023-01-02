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
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(auto&aa:a)cin>>aa;
    for(auto&bb:b)cin>>bb;
    vector<vector<int>> dp(n+1,vector<int>(m+1,INF));
    dp[0][0]=0;
    rep(i,n+1)rep(j,m+1){
        if(i+1<=n&&j+1<=m){
            int t=(a[i]!=b[j]);
            chmin(dp[i+1][j+1],dp[i][j]+t);
        }

        if(i+1<=n)chmin(dp[i+1][j],dp[i][j]+1);
        if(j+1<=m)chmin(dp[i][j+1],dp[i][j]+1);
    }

    cout<<dp[n][m]<<endl;
}