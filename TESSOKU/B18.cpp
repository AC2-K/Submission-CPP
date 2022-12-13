
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
//#include<atcoder/all>	
//using namespace atcoder;  
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
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

template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
int main() {
    int N,S;
    cin>>N>>S;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    //dp判定
    vector<vector<bool>> dp(N+1,vector<bool>(S+1,false));
    dp[0][0]=true;
    rep(i,N)rep(j,S+1){
        if(!dp[i][j])continue;
        dp[i+1][j]=true;
        if(j+A[i]<=S)dp[i+1][j+A[i]]=true;
    }
    if(!dp[N][S]){cout<<-1<<endl;return 0;}
    //復元
    int pos=S;
    vector<int> ans;
    for(int i=N;i>=1;i--){
        //遷移は下のような感じ
        //dp[i][j]=dp[i-1][j] or dp[i-1][j-A[i-1]]
        if(dp[i-1][pos])continue;  //もし、dp[i-1][j]からそのままだったら、使わずに作れる
        //そうでないなら、A[i]を使っている
        ans.push_back(i);  //なお、1-indexに直すことに注意
        pos-=A[i-1];
    }
    cout<<ans.size()<<endl;
    reverse(all(ans));
    for(auto a:ans)cout<<a<<' '; 
}