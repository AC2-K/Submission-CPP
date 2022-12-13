#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
//#include<atcoder/all>	  
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define chmin(x,y) (x)=min(x,y);
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);
int main() {
    //DPする
    //3の倍数<=>各桁の和が3の倍数
    //部分和問題に帰着させてみる

    string S;
    cin>>S;
    int N=S.size();
    vector<int> A(N);
    rep(i,N){
        A[i]=S[i]-'0';
    }
    vector<vector<int>> dp(N+1,vector<int>(201,INF));
    dp[0][0]=0;
    rep(i,N){
        for(int j=0;j<=200;j++){
            if(dp[i][j]>=INF)continue;

            chmin(dp[i+1][j+A[i]],dp[i][j]);
            chmin(dp[i+1][j],dp[i][j]+1);
        }
    }
    int ans=INF;
    for(int i=0;i<=200;i++){
        if(i%3==0){
            if(dp[N][i]>=N)continue;
            else chmin(ans,dp[N][i]);
        }
    }
    if(ans>=INF)cout<<-1<<endl;
    else cout<<ans<<endl;
}