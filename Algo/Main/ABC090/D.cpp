#include<bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
int main() {
    int N,K;
    cin>>N>>K;
    ll ans=0;
    for(int b=1;b<=N;b++){
        ll a=N*max(0,b-K);
        ll L = K + b * N;
        ll R = N;
        if (L <= R) a += R - L + 1;
        ans+=a;
    }
    cout<<ans<<endl;
}