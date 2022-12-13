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
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };

using mint=modint1000000007;
int main() {
    int S;
    cin>>S;
    vector<mint> dp(S+1);
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=S;i++){
        for(int j=0;j<=i-3;j++){
            dp[i]+=dp[j];
        }
    }
    cout<<dp[S].val()<<endl;
}