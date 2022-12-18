#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int N;
    cin>>N;
    int M;
    cin>>M;
    vector<string> S(N);
    rep(i,N){
        cin>>S[i];
    }
    int cnt=0;
    rep(i,N)rep(j,N){
        if(i==j)continue;
        bool check=true;
        rep(k,M){
            if(S[i][k]=='x'&&S[j][k]=='x')check=false;
        }
        if(check)cnt++;
    }
    cout<<cnt/2<<endl;
}