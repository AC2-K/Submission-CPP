#include<bits/stdc++.h>
using namespace std;
int main() {
  int N;
	cin >> N;
	vector<int> A(N), B(N), C(N);
	for(int i=0;i<N;i++)cin >> A[i] >> B[i] >> C[i];
	vector<vector<int>> dp(N, vector<int>(3));
	dp[0][0] = A[0];
	dp[0][1] = B[0];
	dp[0][2] = C[0];
	for (int i = 1;i < N;i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + A[i];
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + B[i];
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + C[i];
	}
	cout << max({ dp[N - 1][0],dp[N - 1][1],dp[N - 1][2] }) << endl;
}