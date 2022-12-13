#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
/*めも
(求めるもの):
|LIS(A)|=3なるAの個数
(条件)
LEN=N
a_i in (1,2,...,M)
|LIS(A)|=3->strictなので注意!!!

N<=10^3
3<=M<=10
(方針)
LIS->とりあえずDP...?
ほしい情報
-> a.back,現在のLIS,
dp[i][j][k][l][m]->先頭i個を見る。LIS(A)=(j,k,l)となるような方法の数...?


ギブ!!!


解答:
dp[i][a_1][a_2][a_3]:=長さiで、長さjのLISの最後尾として考えられる最小値がa_jとなるような部分列はいくつ?
遷移は実装を見よう!!!
*/

template<ll mod>class modint {
private:
    using mint = modint<mod>;
    ll value = 0;
public:

    modint(ll v = 0) {
        v %= mod;
        v = (v + mod) % mod;
        value = v;
    }
    //getter
    ll val() {
        return value;
    }
    /*演算子*/
    mint operator+(mint fp) {
        return mint(value + fp.val());
    }
    mint operator-(mint fp) {
        return mint(value - fp.val());
    }
    mint operator*(mint fp) {
        return mint(value * fp.val());
    }

    /*代入+演算*/
    void operator+=(mint fp) {
        value = ((value + fp.val() + mod) % mod + mod) % mod;
    }
    void operator-=(mint fp) {
        value = value - fp.val();
        value %= mod;
        value += mod;
        value %= mod;
    }
    void operator*=(mint fp) {
        value = value * fp.val();
        value = (value % mod + mod) % mod;
    }
    /*比較演算子*/
    bool operator==(mint fp) {
        return value == fp.val();
    }
    bool operator<(mint fp) {
        return value < fp.val();
    }
    bool operator>(mint fp) {
        return value > fp.val();
    }
    bool operator<=(mint fp) {
        return value <= fp.val();
    }
    bool operator>=(mint fp) {
        return value >= fp.val();
    }

    /*inv*/
    ll inv() {
        return mod_pow(mod - 2);
    }
    ll mod_pow(ll exp) {
        if (exp < 0)exp += (mod - 1);
        if (exp == 0)return 1;
        if (exp == 1)return value;
        ll ret = mod_pow(exp / 2);
        return ret * ret % mod * mod_pow(exp % 2);
    }
    mint operator/(mint a) {
        return mint(value * a.inv());
    }
    void operator/=(mint a) {
        value = value * a.inv();
    }
    //入出力
};
template<ll T>istream& operator>>(istream& is, modint<T>& mt) {
    ll v;
    is >> v;
    mt = v;
    return is;
}
template<ll T>ostream& operator << (ostream& os, modint<T>& mt) {
    return os << mt.val();
}
int main() {
    using mint=modint<MOD2>;
    int n,m;
    cin>>n>>m;
    mint dp[n+1][m+2][m+2][m+2];
    dp[0][m+1][m+1][m+1]=1;     //a_j=m+1:|LIS|=jなるモノがそもそもない。
    rep(i,n)for(int a1=1;a1<=m+1;a1++)for(int a2=1;a2<=m+1;a2++)for(int a3=1;a3<=m+1;a3++){
        for(int x=1;x<=m;x++){
            //一番後ろにxを付け足す。この時の遷移は...
            //x<=a1->最後尾x,LIS(a).size()=1とできる。
            //x<=a2->最後尾x,LIS(a).size()=2とできる
            //x<=a3->最後尾x,LIS(a).size()=3とできる。
            //それ以外は、特に何も起きない。
            mint now=dp[i][a1][a2][a3];
            if(x<=a1)dp[i+1][x][a2][a3]+=now;
            else if(x<=a2)dp[i+1][a1][x][a3]+=now;
            else if(x<=a3)dp[i+1][a1][a2][x]+=now;
        }
    }
    mint ans=0;
    for(int a1=1;a1<=m;a1++)for(int a2=1;a2<=m;a2++)for(int a3=1;a3<=m;a3++){
        ans+=dp[n][a1][a2][a3];
    }
    cout<<ans<<endl;
}