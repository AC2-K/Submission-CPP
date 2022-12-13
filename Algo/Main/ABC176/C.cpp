#include<bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long long> A(N);
	for (int i = 0; i < N; i++)cin >> A[i];
	long long ans = 0;
	for (int i = 1; i < N; i++) {
		if (A[i - 1] <= A[i])continue;
		else {
			ans += A[i - 1] - A[i];
			A[i] = A[i - 1];
		}
	}
	cout << ans << endl;
}