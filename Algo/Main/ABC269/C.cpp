#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<bitset>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
    ll N;
    cin>>N;
    vector<ll> res={0};
    rep(i,60){
        if(N&(1ll<<i)){
            for(auto r:res){
                res.push_back(r|(1ll<<i));
            }
        }
    }
    sort(all(res));
    for(auto r:res)cout<<r<<endl;
}