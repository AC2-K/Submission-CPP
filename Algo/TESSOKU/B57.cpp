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
int fn(int N){
    string s=to_string(N);
    int sum=0;
    for(auto c:s)sum+=c-'0';
    return N-sum;
}
int main() {
    //ダブリングでやる
    int N,K;
    cin>>N>>K;
    vector<vector<int>> dp(32,vector<int>(N+1));
    for(int i=1;i<=N;i++)dp[0][i]=fn(i);
    rep(i,31)for(int j=1;j<=N;j++){
        dp[i+1][j]=dp[i][dp[i][j]];
    }
    for(int n=1;n<=N;n++){
        int val=n;
        for(int i=31;i>=0;i--){
            if(K&(1<<i))val=dp[i][val];
        }
        cout<<val<<endl;
    }
}