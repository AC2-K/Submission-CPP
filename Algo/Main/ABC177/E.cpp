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
const int MAX_N=1e6;
bool check1(vector<int> A){
    set<int> primes;
    for(auto aa:A){ 
        auto pf=fact(aa);
        for(auto element:pf){
            int p=element.first;
            if(primes.find(p)!=primes.end())return false;
            primes.insert(p);
        }
    }
    return true;
}
ll gcd(ll a, ll b) {
    if (a % b == 0)return b;
    else return gcd(b, a % b);
}
bool check2(vector<int> A){
    int GCD=A[0];
    for(auto aa:A)GCD=gcd(GCD,aa);
    return GCD==1;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    if(check1(a))cout<<"pairwise coprime"<<endl;
    else if(check2(a))cout<<"setwise coprime"<<endl;
    else cout<<"not coprime"<<endl;
}