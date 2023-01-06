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
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n)cin >> h[i];
	for (int i = n - 2;i >= 0;i--) {
		if (h[i] > h[i + 1] + 1) {
			cout << "No\n";
			return 0;
		}
		else if(h[i]==h[i+1]+1) {
			h[i]--;
		}
	}
	cout << "Yes\n";
	return 0;
}