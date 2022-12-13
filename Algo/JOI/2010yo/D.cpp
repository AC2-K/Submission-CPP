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
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    const int maxSum=20;
    vector<vector<ll>> dp(N,vector<ll>(maxSum+1));    //@dp[i][S]:先頭i個をいじって、Sにする方法
    dp[0][A[0]]=1;
    rep(i,N-1)rep(S,maxSum+1){
        if(S+A[i+1]<=maxSum)dp[i+1][S]+=dp[i][S+A[i+1]];
        if(S-A[i+1]>=0)dp[i+1][S]+=dp[i][S-A[i+1]];
    }
    cout<<dp[N-2][A[N-1]]<<endl;
}