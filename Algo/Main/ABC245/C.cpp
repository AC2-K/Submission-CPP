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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);
    rep(i, n)cin >> a[i + 1];
    rep(i, n)cin >> b[i + 1];
    vector<vector<bool>> dp(n + 1, vector<bool>(2, false));
    dp[1][0] = true;
    dp[1][1] = true;
    for (int i = 1; i < n; i++) {
        if (dp[i][0]) {
            //一番後ろがAから取ってきたとき...

            if (abs(a[i] - a[i + 1]) <= k)dp[i + 1][0] = true;
            if (abs(a[i] - b[i + 1]) <= k)dp[i + 1][1] = true;  
        }
        if (dp[i][1]) {
            //一番後ろをBから取ってきたとき

            if (abs(b[i] - a[i + 1]) <= k)dp[i + 1][0] = true;
            if (abs(b[i] - b[i + 1]) <= k)dp[i + 1][1] = true;
        }
    }
    if (dp[n][0] || dp[n][1])cout << "Yes\n";
    else cout << "No\n";
}