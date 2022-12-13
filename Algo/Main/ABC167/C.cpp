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
	int N, M, X;
	cin >> N >> M >> X;
	vector<int> C(N);
	vector<vector<int>> A(N, vector<int>(M));
	rep(i, N) {
		cin >> C[i];
		rep(j, M)cin >> A[i][j];
	}
	int ans = INF;
	rep(tmp, 1 << N) 
	{
		int cost = 0;
		vector<int> lev(M);
		rep(i, N)
		{
			if (!(tmp & (1 << i)))continue;
			cost += C[i];
			rep(j, M)
			{
				lev[j] += A[i][j];
			}
		}
		bool check = true;
		rep(i, M) {
			if (lev[i] < X)check = false;
		}
		if (check) {
			ans = min(ans, cost);
		}
	}
	if (ans >= INF)cout << -1 << endl;
	else cout << ans << endl;
}