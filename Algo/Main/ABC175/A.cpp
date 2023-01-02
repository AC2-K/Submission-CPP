#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<bitset>
#include<math.h>
#define rep(i, N)  for(int i=0;i<(N);i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using Node = pair<int, int>;
const ll INF = 1000000000;

int gcd(int a, int b) {
	if (a % b == 0)return b;
	else return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int roundup(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min({ a,b,c,d }) << endl;
}