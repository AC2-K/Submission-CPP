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
    set<string> stop;
    int n,m;
    cin>>n>>m;
    vector<string> st(n);
    rep(i,n)cin>>st[i];
    rep(i,m){
        string s;
        cin>>s;
        stop.insert(s);
    }
    rep(i,n){
        if(stop.count(st[i]))cout<<"Yes\n";
        else cout<<"No\n";
    }
}