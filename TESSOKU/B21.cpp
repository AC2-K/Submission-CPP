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
    string S;
    cin >> S;
    vector<vector<int>> dp(N, vector<int>(N));
    rep(i, N) dp[i][i] = 1;
    rep(i, N - 1) if (S[i] == S[i + 1]) dp[i][i + 1] = 2;
    for (int len = 1; len < N; len++)
    {
        rep(l, N)
        {
            int r = l + len - 1;
            if (r >= N)continue;
            if (l > 0 && r < N - 1)
            {
                if (S[l - 1] == S[r + 1])
                    dp[l - 1][r + 1] = max(dp[l - 1][r + 1], dp[l][r] + 2); //左右広げる
                else
                    dp[l - 1][r + 1] = max(dp[l - 1][r + 1], dp[l][r]);
            }
            if (0 <= l - 1)
                dp[l - 1][r] = max(dp[l - 1][r], dp[l][r]); //増えるわけではない...
            if (r + 1 < N)
                dp[l][r + 1] = max(dp[l][r + 1], dp[l][r]);
        }
    }
    cout << dp[0][N - 1] << endl;
}