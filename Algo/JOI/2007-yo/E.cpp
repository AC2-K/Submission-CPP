#include<bits/stdc++.h>
using namespace std;
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
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int R,C;
    cin>>R>>C;
    vector<int> S(C);
    rep(i,R)rep(j,C){
        int a;
        cin>>a;
        if(a==1)S[j]|=1<<i;
    }
    int ans=0;
    rep(i,1<<R){
        int res=0;
        rep(j,C){
            int Xor=i^S[j];
            int popcount=__builtin_popcount(Xor);
            res+=max(popcount,R-popcount);
        }
        ans=max(ans,res);
    }
    cout<<ans<<endl;
}