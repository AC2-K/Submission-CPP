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
    vector<ll> a(n);
    for(auto&aa:a)cin>>aa;
    vector<ll> sum(n+1);
    rep(i,n)sum[i+1]=sum[i]+a[i];
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,infl));
    auto rec=[&](auto f,int l,int r)-> ll {
        if(dp[l][r]!=infl)return dp[l][r];

        if(l==r)return dp[l][r]=0;
        ll res=infl;
        for(int cut=l;cut<r;cut++){
            chmin(res,f(f,l,cut)+f(f,cut+1,r));
        }

        return dp[l][r]=res+sum[r]-sum[l-1];
    };
    cout<<rec(rec,1,n)<<endl;
}