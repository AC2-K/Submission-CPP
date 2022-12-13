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
    int X;
    cin>>X;
    vector<int> A(N),B(N);
    rep(i,N)cin>>A[i]>>B[i];
    vector<vector<bool>> dp(N+1,vector<bool>(X+1,false));
    dp[0][0]=true;
    rep(i,N)rep(j,X+1){
        if(!dp[i][j])continue;
        if(j+A[i]<=X)dp[i+1][j+A[i]]=true;
        if(j+B[i]<=X)dp[i+1][j+B[i]]=true;
    }
    if(dp[N][X])cout<<"Yes\n";
    else cout<<"No\n";
}