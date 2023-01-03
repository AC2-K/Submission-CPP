#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
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
const ll MOD = 10000;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main()
{
    int N;
    cin >> N;
    int ans = 0;
    rep(i, N)
    {
        char c;
        int a;
        cin >> c >> a;
        if (c == '+')
            ans += a;
        else if (c == '-')
            ans -= a;
        else
            ans *= a;

        ans = (ans + MOD) % MOD;
        cout << ans << '\n';
    }
}