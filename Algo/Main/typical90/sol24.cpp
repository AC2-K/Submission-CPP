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
    int K;
    cin>>K;
    vector<int> A(N),B(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    rep(i,N){
        K-=abs(A[i]-B[i]);
    }
    if(K<0)cout<<"No\n";
    else if(K>=0&&K%2==0)cout<<"Yes\n";
    else cout<<"No\n";
}