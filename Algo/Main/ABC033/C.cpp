#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
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
        return query(a, b, 0, 0, n); 
    }
    int find(int lim){
        int l=0,r=n,k=0;
        while(r-l>1){
            int mid=(l+r)/2;
            if(lim<=dat[k*2+1]){
                r=mid;
            }else{
                lim-=
            }
        }
    }
    X get(int pos){return dat[pos+n-1];}
};

const int M=200000;
SegmentTree<int> cnt(M+1,[](int a,int b){return 0;},0);
int search(int x){
    int ng=0,ok=M;
    while(abs(ok-ng)>1){
        int mid=(ok+ng)/2;
        if(cnt.query(1,mid+1)>x)ok=mid;
        else ng=mid;
    }
    cnt.update(x,0);
    return ok;
}
int main() {
    int Q;
    cin>>Q;
    while(Q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            cnt.update(x,1);
        }else{
            int x;
            cin>>x;
            cout<<search(x)<<endl;
        }
    }
}