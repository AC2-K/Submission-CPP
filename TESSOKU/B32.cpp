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
    int N,K;
    cin>>N>>K;
    vector<int> A(K);
    rep(i,K)cin>>A[i];

    vector<int> dp(N+1,false);      //@dp[i]:=残りi個の状態で手番が回ってきた時勝てるか?
    for(int i=0;i<=N;i++){
        if(dp[i])continue;
        rep(j,K){
            if(i+A[j]<=N)dp[i+A[j]]=true;
        }
    }
    cout<<(dp[N]? "First\n":"Second\n");
}