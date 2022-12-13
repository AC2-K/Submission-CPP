#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
//#include<iomanip>
//#include<limits>
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
using mint=modint1000000007;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int n;
    cin>>n;
    vector<mint> dp(n+1);
    dp[0]=0;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
    cout<<dp[n].val()<<endl;
}