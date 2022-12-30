#include<bits/stdc++.h>
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
//cout << fixed << setprecision(10);
int main() {
	int n, k;
	cin >> n >> k;
	if (n <= k) {
		cout << 0 << endl;
		return 0;
	}
	vector<ll> h(n);
	rep(i, n)cin >> h[i];
	sort(all(h));
	reverse(all(h));
	rep(i, k)h[i] = 0;
	ll ans = 0;
	rep(i, n)ans += h[i];
	cout << ans << endl;
	return 0;
}