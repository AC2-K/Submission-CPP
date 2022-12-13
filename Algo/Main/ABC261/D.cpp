#include<bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N,M;
    cin>>N>>M;
    vector<int> X(N);
    rep(i,N)cin>>X[i];
    vector<ll> Y(N+1);
    rep(i,M){
        int c,y;
        cin>>c>>y;
        Y[c]=y;
    }
    vector<vector<ll>> dp(N+1,vector<ll>(N+1,-1));      //dp[i][j]:=i回目のコイントスで、カウンタがjとなるときの利益
    dp[0][0]=0;
    rep(i,N)rep(j,N+1){
        if(dp[i][j]==-1)continue;
        if(j+1<=N)dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+X[i]+Y[j+1]);
        dp[i+1][0]=max(dp[i+1][0],dp[i][j]+Y[0]);
    }
    ll ans=0;
    rep(j,N+1){
        ans=max(ans,dp[N][j]);
    }
    cout<<ans<<endl;
}