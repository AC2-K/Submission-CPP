#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
    int N;
    cin>>N;
    vector<int> H(N);
    rep(i,N)cin>>H[i];
    vector<int> dp(N,INF);
    dp[0]=0;
    rep(i,N){
        if(i+1>=N)continue;
        int cost1=abs(H[i+1]-H[i]);
        chmin(dp[i+1],dp[i]+cost1);
        if(i+2>=N)continue;
        int cost2=abs(H[i+2]-H[i]);
        chmin(dp[i+2],dp[i]+cost2);
    }
    cout<<dp[N-1]<<endl;
}