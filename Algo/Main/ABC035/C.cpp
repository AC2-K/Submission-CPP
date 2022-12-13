#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
    int n,q;
    cin>>n>>q;
    vector<int> imos(n+2);
    rep(i,q){
        int l,r;
        cin>>l>>r;
        imos[l]++;
        imos[r+1]--;
    }
    vector<int> ans(n+2);
    for(int i=1;i<=n;i++){
        ans[i]=ans[i-1]+imos[i];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]%2;
    }
}