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
    int H,W;
    cin>>H>>W;
    vector<vector<int>> A(H,vector<int>(W));
    rep(i,H)rep(j,W){
        cin>>A[i][j];
    }
    vector<int> sum1(H);
    rep(i,H)rep(j,W)sum1[i]+=A[i][j];
    vector<int> sum2(W);
    rep(j,W)rep(i,H)sum2[j]+=A[i][j];

    vector<vector<int>> ans(H,vector<int>(W));
    rep(i,H)rep(j,W){
        ans[i][j]=sum1[i]+sum2[j]-A[i][j];
    }
    rep(i,H){
        rep(j,W){
            cout<<ans[i][j]<<' ';
        }
        cout<<'\n';
    }
}