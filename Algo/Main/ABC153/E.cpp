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
    int H,N;
    cin>>H>>N;
    vector<int> A(N),B(N);
    rep(i,N)cin>>A[i]>>B[i];
    vector<int> dp(H+1,INF);    //@dp:dp[i]=(Healthをi減らすためにするために必要なコスト)
    dp[0]=0;
    rep(i,H)rep(j,N){
        chmin(dp[min(H,i+A[j])],dp[i]+B[j]);
    }
    cout<<dp[H]<<endl;
}