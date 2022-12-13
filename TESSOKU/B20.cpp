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
int diff(string s,string t){
  vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,INF));
  dp[0][0] = 0;
  dp[1][0]=1;
  dp[0][1]=1;
  for (int i = 0; i < (int)s.size(); ++i) {
    for (int j = 0; j < (int)t.size(); ++j) {
      if (s[i] == t[j]) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
       else dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 1);
      
      if (i >= 0) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j+1] + 1);
      if (j >= 0) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i+1][j] + 1);
    }
  }

  return dp[s.size()][t.size()];
}
int main() {
    string s,t;
    cin>>s>>t;
    cout<<diff(s,t)<<endl;
}
