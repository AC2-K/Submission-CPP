#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int N;
    cin>>N;
    vector<ll> dp(N,INF);
    vector<ll> S(N),T(N);
    rep(i,N)cin>>S[i];
    rep(i,N)cin>>T[i];
    dp[0]=T[0];
    for(int i=0;i<2*N;i++){
        dp[(i+1)%N]=min(T[(i+1)%N],dp[i%N]+S[i%N]);
    }
    rep(i,N)cout<<dp[i]<<endl;
}