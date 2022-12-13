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
    int N;
    cin>>N;
    vector<int> P(N+1,-1),A(N+1);
    for(int i=1;i<=N;i++)cin>>P[i]>>A[i];
    vector<vector<int>> dp(N+1,vector<int>(N+1));  //dp[l][r]:=lからrまでの区間が残っているとき、スコアの最大値
    dp[1][N]=0;  //全部残ってるときは当然スコアは0
    //dp[l][r]=max(dp[l-1][r]+score1,dp[l][r+1]+score2)
    //score1:=もしl<=P[l-1]<=rならA[l-1],でなければ0
    //score2:=上と同じ

    for(int len=N-2;len>=0;len--){
        for(int l=1;l<=N-len;l++){
            int r=l+len;
            if(!(l<=r&&r<=N))continue;

            int score1=0;
            if(l<=P[l-1]&&P[l-1]<=r)score1=A[l-1];
            int score2=0;
            if(l<=P[r+1]&&P[r+1]<=r)score2=A[r+1];

            if(l==1){
                dp[l][r]=dp[l][r+1]+score2;
            }
            else if(r==N){
                dp[l][r]=dp[l-1][r]+score1;
            }
            else{
                dp[l][r]=max(dp[l-1][r]+score1,dp[l][r+1]+score2);
            }
        }
    }

    int ans=-1;
    for(int i=1;i<=N;i++)ans=max(ans,dp[i][i]);
    cout<<ans<<endl;
}