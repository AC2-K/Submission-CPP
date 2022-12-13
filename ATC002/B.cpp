#include <bits/stdc++.h>
using namespace std;
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
ll mod_pow(ll base, ll exp, ll mod = 1e9 + 7)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base % mod;
    ll half = mod_pow(base, exp / 2, mod);
    ll ret = (half * half) % mod;
    if (exp % 2 == 1)
        ret = ret * base % mod;
    return ret;
}
int main()
{
    ll n, m, p;
    cin >> n >> m >> p;
    cout << mod_pow(n, p, m) << endl;
}