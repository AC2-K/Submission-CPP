#include<bits/stdc++.h>
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
void chmax(ll&a,ll b){a=max(a,b);}
int main() {
    int N,W;
    cin>>N>>W;
    vector<int> w(N),v(N);
    rep(i,N)cin>>w[i]>>v[i];
    vector<vector<ll>> dp(N+1,vector<ll>(W+1,-1));
    dp[0][0]=0;
    rep(i,N)rep(j,W+1){
        if(dp[i][j]==-1)continue;
        chmax(dp[i+1][j],dp[i][j]);
        if(j+w[i]<=W)chmax(dp[i+1][j+w[i]],dp[i][j]+v[i]);
    }
    ll ans=0;
    rep(i,W+1)chmax(ans,dp[N][i]);
    cout<<ans<<endl;
}