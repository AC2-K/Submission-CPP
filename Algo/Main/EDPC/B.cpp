#include<bits/stdc++.h>
using namespace std;
int main() {
	const int INF = 1000000000;
	int N, K;
	cin >> N >> K;
	vector<int> dp(N,INF), H(N);
	for (int i = 0;i < N;i++)cin >> H[i];
	dp[0] = 0;
	for (int i = 1;i < N;i++) {
		for (int j = 1;j <= K;j++) {
          if(i-j>=0)dp[i]=min(dp[i],dp[i-j]+abs(H[i]-H[i-j]));
		}
	}
	cout << dp[N - 1] << endl;
}