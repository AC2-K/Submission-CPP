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
    int H,W;
    cin>>H>>W;
    vector<vector<char>> s(H+1,vector<char>(W+1));
    for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)cin>>s[i][j];
    vector<vector<int>> countI(H+1,vector<int>(W+1));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            countI[i][j]=countI[i][j-1]+(s[i][j]=='I');
        }
    }
    vector<vector<int>> countO(H+1,vector<int>(W+1));
    for(int j=1;j<=W;j++){
        for(int i=1;i<=H;i++){
            countO[i][j]=countO[i-1][j]+(s[i][j]=='O');
        }
    }
    ll ans=0;
    for(int i=1;i<=H;i++)for(int j=1;j<=W;j++){
        if(s[i][j]!='J')continue;
        ll J=countO[H][j]-countO[i][j];
        ll I=countI[i][W]-countI[i][j];
        ans+=J*I;
    }
    cout<<ans<<endl;
}