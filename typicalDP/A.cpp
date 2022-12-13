#include <bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;
// cout << fixed << setprecision(10);
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main()
{
    int N;
    cin >> N;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    const int sumMax = 10000;
    vector<vector<bool>> dp(N + 1, vector<bool>(sumMax + 1, false));
    dp[0][0] = true;
    rep(i, N)
    {
        rep(j, sumMax + 1)
        {
            if (!dp[i][j])
                continue;
            dp[i + 1][j] = true;
            dp[i + 1][j + P[i]] = true;
        }
    }
    int val = 0;
    rep(i, sumMax)
    {
        if (dp[N][i])
            val++;
    }
    cout << val << endl;
}