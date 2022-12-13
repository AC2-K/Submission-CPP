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
int main()
{
	int H, W, K;
	cin >> H >> W >> K;
	vector<string> G(H);
	rep(i, H)cin >> G[i];
	int ans = 0;
	for (int tmp1 = 0; tmp1 < (1 << H); tmp1++)for (int tmp2 = 0; tmp2 < (1 << W); tmp2++) {
		vector<string> g(H);
		rep(i, H)rep(j, W) {
			if (tmp1 & (1 << i) || tmp2 & (1 << j))g[i][j] = '.';
			else g[i][j] = G[i][j];
		}
		int cnt = 0;
		rep(i, H)rep(j, W) {
			if (g[i][j] == '#')cnt++;
		}
		if (cnt == K)ans++;
	}
	cout << ans << endl;
}