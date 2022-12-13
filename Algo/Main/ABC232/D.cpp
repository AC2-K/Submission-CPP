#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
#include<cmath>
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    rep(i,h)cin>>s[i];
    vector<vector<int>> dp(h,vector<int>(w));
    dp[0][0]=1;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#')continue;
        if(i-1>=0)dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
        if(j-1>=0)dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
    }
    int ans=-1;
    rep(i,h)rep(j,w){
        ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}