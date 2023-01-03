#include <bits/stdc++.h>
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
int main()
{
    int N, M;
    cin >> N >> M;
    vector<ll> A(M);
    //クーポンを先にbitで持っておく。
    rep(i, M)
    {
        ll pow = 1;
        rep(j, N)
        {
            int a;
            cin >> a;
            A[i] += a * pow;
            pow *= 2;
        }
    }
    vector<vector<ll>> dp(M + 1, vector<ll>(1 << N, INF));
    dp[0][0]=0;
    rep(i,M){
        rep(j,1<<N){
            if(dp[i][j]>=INF)continue;
            
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);  //使わない
            dp[i+1][j|A[i]]=min(dp[i+1][j|A[i]],dp[i][j]+1);  //使う
        }
    }
    if(dp[M][(1<<N)-1]<INF)cout<<dp[M][(1<<N)-1]<<endl;
    else cout<<-1<<endl;
}