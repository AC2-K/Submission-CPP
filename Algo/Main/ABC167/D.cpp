#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N;
    cin>>N;
    ll K;
    cin>>K;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<vector<int>> dp(61,vector<int>(N+1));    //dp[i][j]:=jに到達したあと2^iあとの位置
    for(int i=1;i<=N;i++)dp[0][i]=A[i];

    for(int i=0;i<60;i++)for(int j=1;j<=N;j++){
            dp[i+1][j]=dp[i][dp[i][j]];
    }
    int place=1;
    for(int i=60;i>=0;i--){
        if(K&(1ll<<i))place=dp[i][place];
    }
    cout<<place<<endl;
}