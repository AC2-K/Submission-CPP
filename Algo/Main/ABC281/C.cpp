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
    ll N,T;
    cin>>N>>T;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    ll sum=0;
    rep(i,N)sum+=A[i];
    T%=sum;
    vector<ll> S(N+1);
    rep(i,N)S[i+1]=S[i]+A[i];
    auto id=lower_bound(all(S),T)-S.begin();
    cout<<id<<' ';
    cout<<T-S[id-1]<<endl;
}