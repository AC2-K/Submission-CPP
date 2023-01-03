#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N;
    cin>>N;
    vector<int> A(N),B(N);
    rep(i,N-1)cin>>A[i+1];
    rep(i,N-1)cin>>B[i+1];
    vector<int> dp(N+1,-1);
    dp[1]=0;
    for(int i=1;i<N;i++){
        if(dp[i]==-1)continue;
        dp[A[i]]=max(dp[A[i]],dp[i]+100);
        dp[B[i]]=max(dp[B[i]],dp[i]+150);
    }
    cout<<dp[N]<<endl;
}