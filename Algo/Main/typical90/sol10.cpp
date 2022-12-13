#include <bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;
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
    int N;
    cin >> N;
    vector<vector<int>> score(2, vector<int>(N));
    rep(i, N)
    {
        int c, p;
        cin >> c >> p;
        c--;
        score[c][i] = p;
    }
    vector<int> score1(N + 1);
    vector<int> score2(N + 1);
    rep(i,N)score1[i+1]=score1[i]+score[0][i];
    rep(i,N)score2[i+1]=score2[i]+score[1][i];

    int Q;
    cin>>Q;
    rep(i,Q){
        int L,R;
        cin>>L>>R;
        cout<<score1[R]-score1[L-1]<<' '<<score2[R]-score2[L-1]<<'\n';
    }
}