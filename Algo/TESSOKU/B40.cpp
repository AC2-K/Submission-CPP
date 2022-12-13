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
    int N;
    cin>>N;
    map<int,int> mp;
    rep(i,N){
        int a;
        cin>>a;
        a%=100;
        mp[a]++;
    }
    ll ans=0;
    rep(i,100){
        int j=100-i;
        ans+=mp[i]*mp[j];
    }
    ans/=2;
    cout<<ans<<endl;
}