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

    X get(int pos){return dat[pos+n-1];}
};

template<class T>int LIS(vector<T> &a,bool strict=true) {
    int n=(int)a.size();
    vector<T> aval;
    for(auto aa:a)aval.push_back(aa);
    sort(all(aval));
    aval.erase(unique(all(aval)),aval.end());
    SegmentTree<int> dp(n+1,[](int a,int b){return max(a,b);},0);       //dp[i]=最後尾がiとなるようなLISの最大値
    int res=0;
    for(int i=0;i<n;i++){
        int h=lower_bound(all(aval),a[i])-aval.begin();
        h++;
        int upper=h;
        if(!strict)upper++;
        int A=dp.query(0,upper);
        if(dp.query(h,h+1)<A+1){
            dp.update(h,A+1);
            chmax(res,A+1);
        }
    }
    return res;
}
int main() {
    int N;
    cin>>N;
    vector<P> p(N);
    rep(i,N)cin>>p[i].first>>p[i].second;
    sort(all(p),[](P a,P b){
        if(a.first!=b.first)return a.first<b.first;
        return a.second>=b.second;
    });
    vector<int> X(N);
    rep(i,N)X[i]=p[i].second;
    //for(auto xx:X)cout<<xx<<' ';
    cout<<LIS(X)<<endl;
}