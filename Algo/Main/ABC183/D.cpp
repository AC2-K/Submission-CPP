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
int main() {
    ll n,w;
    cin>>n>>w;
    const int m=200000;
    ll a[m+1];
    rep(i,n){
        ll s,t,p;
        cin>>s>>t>>p;
        a[s]+=p;
        a[t]-=p;
    }
    ll b[m+1];
    b[0]=a[0];
    rep(i,m){
        b[i+1]=b[i]+a[i+1];
    }
    rep(i,m+1){
        ll bb=b[i];
        if(bb>w){
            cout<<"No\n";
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}