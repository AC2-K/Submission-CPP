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
    ll n,x,m;
    cin>>n>>x>>m;
    
    auto f=[&](ll v)-> ll {
        return v%m*v%m;
    };
    //memo:v->f(v)->f2(v)->...->vのサイクルがある。

    const int max_bit=55;
    vector<vector<ll>> dp(max_bit+1,vector<ll>(m)),sum(max_bit+1,vector<ll>(m));    

    //dp[v][e]:=fを2^e回合成して、vを飛ばしたところ
    //sum[v][e]:=v+f(v)+...+u (2^e項)
    rep(v,m){
        dp[0][v]=f(v);
        sum[0][v]=v;
    }
    rep(i,max_bit)rep(v,m){
        dp[i+1][v]=dp[i][dp[i][v]];
    }

    rep(i,max_bit)rep(v,m){
        sum[i+1][v]=sum[i][v]+sum[i][dp[i][v]];
    }

    ll cur=x;
    ll ans=0;
    for(int i=max_bit;i>=0;i--){
        if(n&(1ll<<i)==0){
            ans+=sum[i][cur];
            cur=dp[i][cur];
        }
    }

    cout<<ans<<endl;
}