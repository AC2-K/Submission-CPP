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
    int N,A,B;
    cin>>N>>A>>B;
    vector<bool> dp(N+1,false);     //dp[i]:=残りの石がi個あるときに、その手番の人は勝てるか?
    //i=0,1,...,min(A,B)の時はfalseなので、全部falseで初期化しておく。
    //dp[i]==false <=> dp[i+A]=true なぜなら、dp[i+A]からAだけ石をのぞくという操作でdp[i]を負けさせることができるから。
    //dp[i]==false <=> dp[i+B]=true 同様

    //範囲外参照に注意する
    for(int i=0;i<=N+1;i++){
        if(dp[i])continue;
        if(i+A<=N)dp[i+A]=true;
        if(i+B<=N)dp[i+B]=true;
    }
    if(dp[N])cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}