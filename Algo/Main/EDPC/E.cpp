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
    int N,W;
    cin>>N>>W;
    vector<ll> v(N),w(N);
    rep(i,N)cin>>w[i]>>v[i];
    const int VALUE_MAX=1e6;
    vector<vector<ll>> dp(N+1,vector<ll>(VALUE_MAX+1,infl));  //dp[i][V]:=先頭i項見る.価値Vにするために必要な重さ

    dp[0][0]=0;
    rep(i,N)rep(j,VALUE_MAX+1){
        if(dp[i][j]>=infl)continue;
        chmin(dp[i+1][j+v[i]],dp[i][j]+w[i]);
        chmin(dp[i+1][j],dp[i][j]);
    }

    for(int i=VALUE_MAX;i>=0;i--){
        if(dp[N][i]<=W){
            cout<<i<<endl;
            return 0;
        }
    }
}