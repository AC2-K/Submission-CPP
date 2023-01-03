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
    int N,Q;
    cin>>N>>Q;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int> X(Q),Y(Q);
    rep(i,Q)cin>>X[i]>>Y[i];
    vector<vector<int>> dp(33,vector<int>(N+1));  //ダブリングの前計算 dp[i][j]:=穴jにいた2^i日後の位置
    rep(i,N+1)dp[0][i]=A[i];
    rep(i,32){
        for(int j=1;j<=N;j++){
            dp[i+1][j]=dp[i][dp[i][j]];
        }
    }
    rep(i,Q){
        int x=X[i],y=Y[i];
        int place=x;
        for(int i=29;i>=0;i--){
            if(y&(1<<i))place=dp[i][place];
        }
        cout<<place<<'\n';
    }
}