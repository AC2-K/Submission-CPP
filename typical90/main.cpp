#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> memo(N+1);
    for (int i = 0; i < N; i++)cin >> memo[i];
    memo[0] = X;
    memo[1] = Y;
    for (int i = 2; i <= N; i++){
        memo[i] = (memo[i - 1] + memo[i - 2]) % 100;  //定義通りに添え字iを動かす。
    }
    cout << memo[N] << endl;
}