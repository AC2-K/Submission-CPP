#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    string s;
    cin>>s;
    int n=s.size();
    const int bit=32;
    vector<vector<int>> dp(n,vector<int>(bit));  //dp[i][e]:=iから2^e経った時の位置
    rep(i,n){
        if(s[i]=='L')dp[i][0]=i-1;
        else dp[i][0]=i+1;
    }
    rep(j,bit)rep(i,n){
        dp[i][j+1]=dp[dp[i][j]][j];
    }
    vector<int> cnt(n);
    rep(i,n){
        cnt[dp[i][bit-1]]++;
    }
    for(auto c:cnt)cout<<c<<' ';
    cout<<endl;
}