#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main()
{
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    rep(i, N) cin >> P[i];
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i,K)que.push(P[i]);
    cout<<que.top()<<'\n';
    for(int i=K;i<N;i++){
        if(P[i]>que.top()){
            que.pop();
            que.push(P[i]);
        }
        cout<<que.top()<<'\n';
    }
}