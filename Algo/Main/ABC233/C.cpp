#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
#include<cmath>
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
    ll X;
    cin>>N>>X;
    vector<vector<ll>> a;
    vector<int> L(N);
    rep(i,N){
        cin>>L[i];
        vector<ll> _a(L[i]);
        rep(j,L[i]){
            cin>>_a[j];
        }
        a.push_back(_a);
    }
    //prod:=現在選んだやつの積
    //pos:=今から調べるところ
    int ans=0;
    auto dfs=[&](auto f,int pos,ll prod=1){
        if(prod>X)return;
        if(pos==N){
            if(prod==X)ans++;
            return;
        }
        rep(i,L[pos]){
            f(f,pos+1,prod*a[pos][i]);
        }
    };
    dfs(dfs,0);
    cout<<ans<<endl;
}