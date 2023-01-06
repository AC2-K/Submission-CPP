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
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto&aa:a)cin>>aa;
    const int m=60; //ceil(log k)
    vector<vector<ll>> dp(m+1,vector<ll>(n)); //dp[i][j]:=現在j(on mod n)入っている時、2^i回操作を行う。飴の個数(mod n)
    for(int i=0;i<n;i++){
        dp[0][i]=a[i];
    }
    rep(i,m)rep(j,n){
		dp[i + 1][j] = dp[i][j] + dp[i][(j+dp[i][j]) % n];
    }
    ll ans=0;
    for(int i=m;i>=0;i--){
        if(k&(1<<i)){
            ans+=dp[m-i+1][ans%n];
        }
    }
    cout<<ans<<endl;
}