#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using namespace atcoder;
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
    int N,W;
    cin>>N>>W;
    vector<ll> w(N),v(N);
    rep(i,N)cin>>w[i]>>v[i];
    vector<vector<ll>> dp(N+1,vector<ll>(100001,INF+1));  //dp[i][j]:=先頭i個を見て、価値がjになるならばその時の重さの最小値
    dp[0][0]=0;
    rep(i,N)rep(j,100001){
        if(dp[i][j]>=INF)continue;
        
        dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        if(j+v[i]<=100001)dp[i+1][j+v[i]]=min(dp[i+1][j+v[i]],dp[i][j]+w[i]);
    }

    for(int j=100000;j>=0;j--){
        if(dp[N][j]<=W){
            cout<<j<<endl;
            return 0;
        }
    }
}