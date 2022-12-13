#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
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
    int N,M;
    cin>>N>>M;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    vector<vector<ll>> dp(N+1,vector<ll>(M+1,-INFL));
    dp[0][0]=0;
    rep(i,N)rep(j,M+1){
        chmax(dp[i+1][j],dp[i][j]);
        if(j+1<=M)chmax(dp[i+1][j+1],dp[i][j]+(j+1)*A[i]);
    }
    cout<<dp[N][M]<<endl;
}