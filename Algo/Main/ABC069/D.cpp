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
    int h,w;
    cin>>h>>w;
    vector<vector<int>> field(h,vector<int>(w));
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    int now=0;
    rep(i,h)rep(j,w){
        field[i][j]=now+1;
        a[now]--;
        if(a[now]==0)now++;
    }
    rep(i,h){
        if(i%2==1){
            reverse(all(field[i]));
        }
    }
    rep(i,h){
        rep(j,w){
            cout<<field[i][j]<<' ';
        }
        cout<<'\n';
    }
}