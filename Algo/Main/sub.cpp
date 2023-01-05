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
template <class X>
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
        //if(a==0&&b==n)return dat[0];
        return query(a, b, 0, 0, n); 
    }

    X get(int pos){return dat[pos+n-1];}
};
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    a=press(a); //座圧する
    graph g(n);
    rep(i,n-1){
        int s,t;
        cin>>s>>t;
        s--;
        t--;
        g[s].push_back(t);
        g[t].push_back(s);
    } 
    SegmentTree<int> dp(n+1,[](int a,int b){return max(a,b);},0);  
    vector<int> ans(n); //ans[v]:=0-vパス上のLIS
    auto dfs=[&](auto f,int v,int par=-1)-> void {
        int V=dp.query(0,a[v]);
        if(par!=-1)ans[v]=max(ans[par],V+1);
        else ans[v]=1;

        int pre_dp=dp.get(a[v]);
        dp.update(a[v],ans[v]);
        for(auto nex:g[v]){
            if(nex==par)continue;
            f(f,nex,v);
        }
        dp.update(a[v],pre_dp);
    };
    dfs(dfs,0);
    for(auto d:ans)cout<<d<<endl;
}