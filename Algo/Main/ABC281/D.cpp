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
    ll N,K,D;
    cin>>N>>K>>D;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(K+1,vector<ll>(D,-1)));
    dp[0][0][0]=0;
    rep(i,N)rep(j,K+1)rep(k,D){
        if(dp[i][j][k]==-1)continue;
        chmax(dp[i+1][j][k],dp[i][j][k]);
        if(j+1<=K){
            chmax(dp[i+1][j+1][(k+A[i]%D)%D],dp[i][j][k]+A[i]);
        }  
    }
    if(dp[N][K][0]==-1)cout<<-1<<endl;
    else cout<<dp[N][K][0]<<endl;
}