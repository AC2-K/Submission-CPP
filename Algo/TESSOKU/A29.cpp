#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
using mint = modint1000000007;
int main()
{
    ll H, W;
    cin >> H >> W;
    ll n = H + W - 2;
    ll r = H - 1;
    mint div = 1;
    mint ans = 1;
    for (int i = 0; i < r; i++)
        ans *= (n - i);
    for (int i = 1; i <= r; i++)
        div *= i;
    ans = ans * div.inv();
    cout << ans.val() << endl;
}