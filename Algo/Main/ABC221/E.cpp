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
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
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
using mint=modint<MOD2>;

template <typename X>
class SegmentTree {
    using fx = function<X(X, X)>;
    int n;
    fx op;
    const X ex;
    vector<X> dat;

    X query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        }
        else if (a <= l && r <= b) {
            return dat[k];
        }
        else {
            X vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return op(vl, vr);
        }
    }
public:
    SegmentTree(int n_, fx fx_, X ex_) : n(), op(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void set(int pos, X x) { 
        dat[pos + n - 1] = x;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
    }

    void update(int pos, X x) {
        pos += n - 1;
        dat[pos] = x;
        while (pos > 0) {
            pos = (pos - 1) / 2;
            dat[pos] = op(dat[pos * 2 + 1], dat[pos * 2 + 2]);
        }
    }
    void add(int pos,X val){
        update(pos,get(pos)+val);
    }

    X query(int a, int b) { 
        if(a==0&&b==n)return dat[0];
        return query(a, b, 0, 0, n); 
    }

    X get(int pos){return dat[pos+n-1];}
};
vector<int> press(vector<int> A){
    vector<int> B;
    vector<int> T;
    rep(i,A.size())T.push_back(A[i]);
    sort(all(T));
    T.erase(unique(all(T)),T.end());    //重複消去
    rep(i,A.size()){
        int pos=lower_bound(all(T),A[i])-T.begin();
        B.push_back(pos+1);
    }
    return B;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    auto T=press(a);
    SegmentTree<mint> seg(n+1,[&](mint a,mint b){return a+b;},0);
    mint ans=0;
    mint inv2=mint(2).inv();
    rep(i,n){
        ans+=seg.query(1,T[i]+1)*mint(2).mod_pow(i);
        mint val=inv2.mod_pow(i+1);
        seg.add(T[i],val);
    }
    cout<<ans<<endl;
}