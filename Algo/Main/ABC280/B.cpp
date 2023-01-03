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
    vector<ll> S(N);
    rep(i,N)cin>>S[i]; 
    vector<ll> A(N);
    A[0]=S[0];
    rep(i,N-1){
        A[i+1]=S[i+1]-S[i];
    }
    rep(i,N)cout<<A[i]<<' ';
    cout<<endl;
}