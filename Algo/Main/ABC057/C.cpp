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
int f(ll a) {
	int res = 0;
	while (a != 0) { res++; a /= 10; }
	return res;
}
int F(ll a, ll b) { return max(f(a), f(b)); }
int main()
{
	ll n;
	cin >> n;
	set<ll> div;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			div.insert(i);
		}
	}
	int ans = INF;
	for (auto d : div) {
		ll d1 = d;
		ll d2 = n / d;
		ans = min(ans, F(d1, d2));
	}
	cout << ans << endl;
}