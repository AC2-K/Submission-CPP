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
    int H,W;
    cin>>H>>W;
    vector<string> G(H);
    rep(i,H)cin>>G[i];
    vector<vector<ll>> dp(H,vector<ll>(W));
    dp[0][0]=1;
    rep(i,H)rep(j,W){
        if(i+1<H&&G[i+1][j]=='.')dp[i+1][j]+=dp[i][j];
        if(j+1<W&&G[i][j+1]=='.')dp[i][j+1]+=dp[i][j];
    }
    cout<<dp[H-1][W-1]<<endl;
}