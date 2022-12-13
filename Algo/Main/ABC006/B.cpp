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
#include<atcoder/all>	
using namespace atcoder;  
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
using mint=modint;
int main() {
    mint::set_mod(10007);
    int N;
    cin>>N;
    if(N<=2){
        cout<<0<<endl;
        return 0;
    }
    else if(N==3){
        cout<<1<<endl;
        return 0;
    }
    vector<mint> dp(N+1);
    dp[1]=0;
    dp[2]=0;
    dp[3]=1;
    for(int i=4;i<=N;i++)dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    cout<<dp[N].val()<<endl;
}