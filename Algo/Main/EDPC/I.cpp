#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    vector<double> p(n);
    for(auto&pp:p)cin>>pp;
    vector<vector<double>> dp(n+1,vector<double>(n+1));   //dp[i][j]:=i回投げて、j回表が出る確率
    dp[0][0]=1.0;
    rep(i,n)rep(j,n+1){
        dp[i+1][j+1]+=dp[i][j]*p[i];
        dp[i+1][j]+=dp[i][j]*(1-p[i]);
    }
    double ans=0;
    for(int i=0;i<=n;i++){
        //i>(n-i) <=>2*i>n

        if(2*i>n)ans+=dp[n][i];
    }
    cout<<setprecision(12);
    cout<<ans<<endl;
}