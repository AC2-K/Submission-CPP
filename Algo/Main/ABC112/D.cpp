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
vector<pair<ll, ll>> fact(ll n) {
    vector<pair<ll, ll>> ret;
    for (ll div = 2; div * div <= n; div++) {
        if (n % div != 0)continue;
        ll exp = 0;
        while (n % div == 0) {
            exp++;
            n /= div;
        }
        ret.push_back(make_pair(div, exp));
    }
    if (n != 1)ret.push_back(make_pair(n, 1));
    return ret;
}
int main() {
    int n,m;
    cin>>n>>m;
    //g(sum(r))==m <=> sum(r)==(m/g)>=n =>m/n>=g
    vector<int> divs;
    for(int d=1;d*d<=m;d++)if(m%d==0)divs.push_back(d),divs.push_back(m/d);
    divs.push_back(m);
    int ans=1;
    for(auto g:divs){
        if(n<=m/g)chmax(ans,g);
    }
    cout<<ans<<endl;
}