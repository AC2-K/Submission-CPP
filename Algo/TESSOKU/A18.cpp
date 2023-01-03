
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
bool subsetSum(int N,int S,vector<int>A){
    vector<vector<bool>> dp(N+1,vector<bool>(S+1,false));
    dp[0][0]=true;
    rep(i,N)rep(j,S+1){
        if(!dp[i][j])continue;
        dp[i+1][j]=true;
        if(j+A[i]<=S)dp[i+1][j+A[i]]=true;
    }
    return dp[N][S];
}
int main() {
    int N,S;
    cin>>N>>S;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    if(subsetSum(N,S,A))cout<<"Yes\n";
    else cout<<"No\n";
}