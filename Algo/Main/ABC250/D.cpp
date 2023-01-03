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
vector<bool> makePrimes(int N) {
    vector<bool> primes(N + 1, true);

    primes[0] = primes[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        if (!primes[p]) continue;
        for (int i = 2; p * i <= N; i++) {
            primes[p * i] = false;
        }
    }

    return primes;
}
int main() {
    ll n;
    cin>>n;
    const int MAX=1e6;
    auto prime_check=makePrimes(MAX);
    vector<ll> p;
    for(int i=1;i<=MAX;i++){
        if(prime_check[i])p.push_back(i);
    }
    int siz=p.size();
    auto check=[&](ll p,ll q)-> bool{
        return p*q*q<=n/q;
    };
    ll ans=0;
    rep(i,siz-1){
        if(!check(p[i],p[i+1]))break;
        int ng=siz;
        int ok=i+1;
        while(abs(ng-ok)>1){
            int mid=(ng+ok)/2;
            if(check(p[i],p[mid]))ok=mid;
            else ng=mid;
        }
        ans+=ok-i;
    }
    cout<<ans<<endl;
}