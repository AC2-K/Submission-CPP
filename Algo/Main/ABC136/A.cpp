#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<bitset>
#define rep(i,N)for(int i=0;i<(int)(N);i++);
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using Node = pair<int, int>;
const ll INF = 1000000000;
int main() {
	int A, B, C;
	cin >> A >> B >> C;
	int D = A - B;
	C -= D;
	if (C < 0)cout << 0 << endl;
	else cout << C << endl;
}