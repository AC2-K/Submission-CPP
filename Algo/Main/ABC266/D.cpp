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
    cin>>N;
    const int M=1e5;
    vector<ll> x(M+1,-1);
    vector<ll> a(M+1);
    rep(i,N){
        ll t,_x,_a;
        cin>>t>>_x>>_a;
        x[t]=_x;
        a[t]=_a;
    }
    vector<vector<ll>> dp(M+1,vector<ll>(5,-INFL));
    dp[0][0]=0;
    for(int i=1;i<=M;i++){
        rep(j,5){
            dp[i][j]=dp[i-1][j];
            if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(j<4)dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
        }
        if(x[i]!=-1)dp[i][x[i]]+=a[i];
    }
    ll ans=0;
    rep(x,5)ans=max(ans,dp[M][x]);
    cout<<ans<<endl;
}