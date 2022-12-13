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
    vector<int> A(N),B(N),C(N),D(N);
    rep(i,N)cin>>A[i];
    rep(i,N)cin>>B[i];
    rep(i,N)cin>>C[i];
    rep(i,N)cin>>D[i];
    set<ll> sum1,sum2;
    rep(i,N)rep(j,N)sum1.insert(A[i]+B[j]);
    rep(i,N)rep(j,N)sum2.insert(C[i]+D[j]);
    for(auto s1:sum1){
        int s2=K-s1;
        if(sum2.find(s2)!=sum2.end()){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}