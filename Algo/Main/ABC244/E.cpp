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
    int n,m;
    cin>>n>>m;
    int k,s,t,x;
    cin>>k>>s>>t>>x;
    s--;
    t--;
    x--;
    Graph g(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    using mint=modint<MOD2>;
    //dp[i][j][k]:=長さi,最後尾がj,xが出た回数を2で割った余りがkとなるようなAの数
    vector<vector<vector<mint>>> dp(k+2,vector<vector<mint>>(n,vector<mint>(2)));
    dp[1][s][0]=1;
    for(int i=1;i<=k;i++)rep(j,n)rep(r,2){
        for(auto nex:g[j]){
            if(nex==x)dp[i+1][nex][1-r]+=dp[i][j][r];
            else dp[i+1][nex][r]+=dp[i][j][r];
        }
    }
    cout<<dp[k+1][t][0]<<endl;
}