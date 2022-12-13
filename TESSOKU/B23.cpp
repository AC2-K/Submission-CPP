#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;

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
void chmin(double &x, double y) { x = min(x, y); }
int main()
{
    // TSP bitDP
    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vector<vector<double>> dist(N, vector<double>(N));
    rep(i, N) rep(j, N)
    {
        double dx = X[i] - X[j];
        double dy = Y[i] - Y[j];
        dist[i][j] = sqrt(dx * dx + dy * dy);
        dist[j][i] = dist[i][j];
    }

    vector<vector<double>> dp(1 << N, vector<double>(N, INF));

    //@dp[S][i] 現在位置iで、今までに通った都市の集合がSとなるとき、この状態に至るまでの最短経路長.

    //当然.どこにも行ってなければそもそも経路長は0;
    dp[0][0]=0;

    rep(S, 1 << N)
    {
        rep(pos, N)
        {
            //到達してなければパスする
            if (dp[S][pos] >= INF)continue;

            rep(nex, N)
            {
                if ((S/(1<<nex))%2==1)continue;     // Sのnexビットが立ってる.すなわち、すでにnexを訪れてたら放置する。

                double d = dist[pos][nex];      // pos->nexで移動してみる
                int T = S | (1 << nex);     //ビットを立てる
                chmin(dp[T][nex], dp[S][pos] + d);
            }
        }
    }
    cout << fixed << setprecision(10);
    cout<<dp[(1<<N)-1][0]<<endl;
}