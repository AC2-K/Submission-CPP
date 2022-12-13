#include<bits/stdc++.h>
#include"atcoder/all"	  
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using namespace atcoder;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
using mint = modint998244353;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);
int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<mint>> dp(K + 1, vector<mint>(N + 1, mint(0)));  //dp[i][j]:=i回回してjにたどり着く確率
	dp[0][0] = 1;

	mint m_inv = mint(1) / M;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j <= N; j++) {
			if (j == N) {
				dp[i + 1][j] += dp[i][j];
				continue;
			}
			for (int l = 1; l <= M; l++) {
				int nxt = j + l;
				if (nxt > N) {
					int over = nxt - N;
					nxt = N - over;
				}
				dp[i + 1][nxt] += dp[i][j]*m_inv;
			}
		}
	}
	cout << dp[K][N].val() << endl;
}