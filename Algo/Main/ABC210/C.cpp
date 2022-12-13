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
    int n,k;
    cin>>n>>k;
    vector<int> c(n);
    for(auto&cc:c)cin>>cc;
    int var=0;
    map<int,int> cnt;
    rep(i,k){
        if(cnt[c[i]]==0)var++;
        cnt[c[i]]++;
    }
    int ans=0;
    chmax(ans,var);
    for(int i=k;i<n;i++){
        if(cnt[c[i-k]]==1)var--;
        cnt[c[i-k]]--;
        if(cnt[c[i]]==0)var++;
        cnt[c[i]]++;
        chmax(ans,var);
    }
    cout<<ans<<endl;
}