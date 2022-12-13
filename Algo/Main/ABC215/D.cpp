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
    vector<bool>check(m+1,false);
    for(int i=1;i<=m;i++)check[i]=true;
    rep(i,n){
        int a;
        cin>>a;
        auto pf=fact(a);
        for(auto e:pf){
            if(!check[e.first])continue;
            for(int j=e.first;j<=m;j+=e.first)check[j]=false;
        }
    }
    vector<int> ans;
    for(int i=1;i<=m;i++){
        if(check[i])ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto a:ans)cout<<a<<endl;
}