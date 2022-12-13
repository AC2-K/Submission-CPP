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
    double dp[N+1];    //dp[i][j]:=iラウンド行ったとする。最後にjが出たときの、スコアの期待値
    double p=1./6.;
    rep(i,N){
        dp[i+1]=p*max(1.,dp[i])+p*max(2.,dp[i])+p*max(3.,dp[i])+p*max(4.,dp[i])+p*max(5.,dp[i])+p*max(6.,dp[i]);
    }
    cout<<dp[N]<<endl;
}