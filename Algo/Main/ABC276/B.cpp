#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
//#include<atcoder/all>	  
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);
int main() {
	int N, M;
	cin >> N >> M;
	Graph G(N);
	rep(i, M) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, N) {
		sort(all(G[i]));
	}
	rep(i, N) {
		cout << G[i].size() << ' ';
		for (auto v : G[i]) {
			cout << v + 1 << ' ';
		}
		cout << '\n';
	}
}