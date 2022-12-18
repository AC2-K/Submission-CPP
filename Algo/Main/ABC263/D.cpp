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

    X query(int a, int b) {
        if(a>=b)return 0;
        return query(a, b, 0, 0, n); 
    }

    X get(int pos){return dat[pos+n-1];}
};
int main() {
    int n,l,r;
    cin>>n>>l>>r;
    
    SegmentTree<ll> a(n,[](ll a,ll b){return a+b;},0);
    rep(i,n){
        ll aa;
        cin>>aa;
        a.set(i,aa);
    }
    a.build();
    int x=0;
    for(int i=1;i<=n;i++){
        auto sum=a.query(0,i);
        if(sum>i*l){
            x=i;
        }
    }
    int y=0;
    for(int i=1;i<=n;i++){
        auto sum=a.query(n-i,n);
        if(sum>i*r)y=i;
    }
    rep(i,y)a.set(n-i,r);
    rep(i,x)a.set(i,l);
    a.build();
    a.build();
    cout<<x<<' '<<y<<endl;
    cout<<a.query(0,n)<<endl;
}