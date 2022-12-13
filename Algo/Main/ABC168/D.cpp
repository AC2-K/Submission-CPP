#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;
//#include<iomanip>
//#include<limits>
// cout << fixed << setprecision(10);
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main()
{
    int N, M;
    cin >> N >> M;
    Graph G(N);
    rep(i, M)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> que;
    vector<int> dist(N, -1);
    vector<int> ans(N, -1);
    dist[0] = 0;
    que.push(0);
    while (!que.empty())
    {
        int t = que.front();
        que.pop();
        for (auto n : G[t])
        {
            if (dist[n] != -1)
                continue;
            dist[n] = dist[t] + 1;
            que.push(n);
        }
    }
    for (int u = 1; u < N; u++)
    {
        if (dist[u] == -1)
        {
            cout << "No" << endl;
            return 0;
        }
        for (auto v : G[u])
        {
            if (dist[v] + 1 == dist[u])
                ans[u] = v;
        }
    }
    cout << "Yes\n";
    for (int u = 1; u < N; u++)
    {
        cout << ans[u] + 1 << '\n';
    }
}