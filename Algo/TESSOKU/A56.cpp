#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
// cout << fixed << setprecision(10);
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
class rollingHash
{
private:
    /*メンバ*/
    ll mod = 998244353;
    ll base = 32;
    string s;
    vector<ll> hash;
    /*modint関連のメソッドを持っておく*/
    ll mod_pow(ll base, ll exp)
    {
        if (exp == 0)
            return 1;
        if (exp == 1)
            return base % mod;
        ll half = mod_pow(base, exp / 2);
        ll ret = (half * half) % mod;
        if (exp % 2 == 1)
            ret = ret * base % mod;
        return ret;
    }
    int id(char c) { return c - 'a' + 1; }

public:
    /*コンストラクタ*/
    rollingHash(string _s, ll _mod = 998244353, ll _base = 100) : s(_s), mod(_mod), base(_base), hash(_s.size() + 1) {}

    /*メソッド*/

    /*ハッシュの表を作る*/
    void build()
    {
        hash[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            hash[i + 1] = (hash[i] * base % mod + id(s[i]) % mod) % mod;
        }
    }

    /*区間ハッシュを求める*/

    ll rangeHash(int l, int r)
    {
        return (hash[r] - mod_pow(base, r - l + 1) * hash[l - 1] % mod + mod) % mod; // hash[l,r]=hash[r]-base^(r-l+1)*hash[l-1]
    }

    bool same(int l, int r, int L, int R)
    {
        bool check = (rangeHash(l, r) == rangeHash(L, R));
        return check;
    }
};

int main()
{
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    rollingHash S(s, 1e9 + 7);
    S.build();

    while (Q--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << (S.same(a, b, c, d) ? "Yes" : "No") << endl;
    }
}