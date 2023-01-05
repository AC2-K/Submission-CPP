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
    ll val() {
        return value;
    }
    mint operator+(mint fp) {
        return mint(value + fp.val());
    }
    mint operator-(mint fp) {
        return mint(value - fp.val());
    }
    mint operator*(mint fp) {
        return mint(value * fp.val());
    }

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

    ll inv() {
        return mod_pow(mod - 2);
    }
    ll mod_pow(ll exp) {
        if (exp < 0)exp += (mod - 1);
        if (exp == 0)return 1;
        if (exp == 1)return value;
        ll ret = mod_pow(exp / 2);
        return ret * ret % mod * mod_pow(exp % 2)%mod;
    }
    mint operator/(mint a) {
        return mint(value * a.inv());
    }
    void operator/=(mint a) {
        value = value * a.inv();
        value%=mod;
    }
};
template<ll T>istream& operator>>(istream& is, modint<T>& mt) {
    ll v;
    is >> v;
    mt = v;
    return is;
}
template<ll T>ostream& operator << (ostream& os, modint<T>& mt) {
    return os << mt.val()%T;
}
using mint=modint<MOD>;
int main() {
    int n;
    cin>>n;
    graph g(n);
    rep(i,n-1){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<mint>> dp(n,vector<mint>(2));
    //0->brack,1->white

    //dp[v][c]:=頂点vを色cで塗るような塗り方(vの部分木に注目する)

    //葉から辿っていく
    auto rec=[&](auto f,int v,int from=-1)-> void {
        //葉の時
        if(g[v].size()==1&&g[v][0]==from){
            dp[v][0]=1;
            dp[v][1]=1;
            return;
        }

        mint black=1;
        mint white=1;
        for(auto ch:g[v]){
            if(ch==from)continue;
            f(f,ch,v);
            black*=dp[ch][1];
            white*=(dp[ch][0]+dp[ch][1]);
        }
        dp[v][0]=black;
        dp[v][1]=white;
    };
    rec(rec,0);
    mint ans=(dp[0][0]+dp[0][1]);
    cout<<ans<<endl;
}