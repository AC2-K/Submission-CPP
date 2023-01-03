#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<ll>> dp(n+1,vector<ll>(m+1));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
        dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        if(s[i-1]==t[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
    }
    cout<<dp[n][m]<<endl;
}