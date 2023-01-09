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
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    rep(i,n+1)rep(j,m+1){
        if(dp[i][j]==-1)continue;
        if(i+1<=n)chmax(dp[i+1][j],dp[i][j]);
        if(j+1<=m)chmax(dp[i][j+1],dp[i][j]);
        if(i<n&&j<n&&s[i]==t[j]){
            chmax(dp[i+1][j+1],dp[i][j]+1);
        }
    }
    string ans;
    int ii=n,jj=m;
    while(ii>=1&&jj>=1){
        if(ii-1>=0&&jj-1>=0&&dp[ii][jj]==dp[ii-1][jj-1]+1){
            ans.push_back(s[ii]);
            ii--;
            jj--;
        }
        else if(ii-1>=0&&dp[ii][jj]==dp[ii-1][jj]){
            ii--;
        }
        else if(jj-1>=0&&dp[ii][jj]==dp[ii][jj-1]){
            jj--;
        }
    }
    reverse(all(ans));
    cout<<ans<<endl;
}