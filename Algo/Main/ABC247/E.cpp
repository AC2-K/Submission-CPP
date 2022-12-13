#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
#include<functional>
template<typename X>
class SegmentTree
{
    using fx = function<X(X, X)>;
    vector<X> dat;
    X ex;
    int siz = 1;
    fx op;

public:
    void init(int N, fx _op, X _ex)
    {
        N++;
        siz = 1;
        while (siz < N)
            siz *= 2;
        dat.resize(siz * 2);
        rep(i, siz * 2) dat[i] = _ex;
        ex = _ex;
        op = _op;
    }
    void init(int N, fx _op, X _ex,vector<int> A)
    {
        N++;
        siz = 1;
        while (siz < N)
            siz *= 2;
        dat.resize(siz * 2);
        rep(i, siz * 2) dat[i] = _ex;
        ex = _ex;
        op = _op;

        rep(i,N){
            update(i+1,A[i]);
        }
    }

    //更新クエリ
    void update(int pos, X x)
    {
        pos = pos + siz - 1;
        dat[pos] = x;
        while (pos >= 2)
        {
            pos /= 2;
            dat[pos] = op(dat[pos * 2], dat[pos * 2 + 1]);
        }
    }

    //もう一方のqueryを起動する
    X query(int l, int r)
    {
        return query(l, r, 1, siz + 1, 1);
    }
    //デバッグ用のShowAll
    void showAll()
    {
        cout << "Size:" << siz << '\n';
        cout << "dat:";
        for (auto d : dat)
            cout << d << ' ';
        cout << '\n';
        cout << "ex:" << ex << '\n';
        return;
    }
    
    // Getクエリ
private:
    X query(int l, int r, int a, int b, int u)
    {
        if (r <= a || b <= l)
            return ex;
        if (l <= a && b <= r)
            return dat[u];
        int m = (a + b) / 2;
        int L = query(l, r, a, m, u * 2);
        int R = query(l, r, m, b, u * 2 + 1);
        return op(L, R);
    }
};
int main() {
    SegmentTree<int> stMax,stMin;
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    vector<int> A(n);
    rep(i,n)cin>>A[i];
    stMax.init(n,[](int a,int b){
        return max(a,b);
    },0,A);
    stMin.init(n,[](int a,int b){
        return min(a,b);
    },INF,A);

    int l=-1,r=-1;
    for(int i=1;i<=n;i++){
    }
    //
}