#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<bitset>
#define rep(i,N)for(int i=0;i<(N);i++)

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using Node = pair<int, int>;
const ll INF = 1000000000;
const vector<int> dx = { 0,0,1,-1 };
const vector<int> dy = { 1,-1,0,0 };
int main() {
	int H, A;
	cin >> H >> A;
	if (H % A == 0)cout << H / A << endl;
	else cout << (int)(H / A + 1) << endl;
}
