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
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto&&aa:a)cin>>aa;
    ll ans=0;
    for(int i=1;i<n;i++){
        if(a[i]+a[i-1]<=x)continue;

        int diff=a[i]+a[i-1]-x;
        a[i]=max(0,a[i]-diff);
        ans+=diff;
    }
    cout<<ans<<endl;
}