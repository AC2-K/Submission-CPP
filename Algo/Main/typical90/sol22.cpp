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
ll gcd(ll a, ll b) {
    if (a % b == 0)return b;
    else return gcd(b, a % b);
}
int main() {
    ll a,b,c;
    cin>>a>>b>>c;
    ll siz=gcd(a,b);
    siz=gcd(siz,c);
    a/=siz,b/=siz,c/=siz;
    cout<<(a-1)+(b-1)+(c-1)<<endl;
}