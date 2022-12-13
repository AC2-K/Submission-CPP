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
int main() {
    int m;
    cin>>m;
    vector<ll> x1(m),y1(m);
    rep(i,m)cin>>x1[i]>>y1[i];
    int n;
    cin>>n;
    vector<ll> x2(n),y2(n);
    rep(i,n)cin>>x2[i]>>y2[i];

    auto check=[&](ll dx,int dy) {
        rep(i,m){
            bool exist=false;
            rep(j,n){
                if(x1[i]+dx==x2[j]&&y1[i]+dy==y2[j])exist=true;
            }
            if(!exist)return false;
        }
        return true;
    };
    rep(i,m){
        ll x0=x1[i],y0=y1[i];
        rep(j,m){
            int dx=x2[j]-x0,dy=y2[j]-y0;
            if(check(dx,dy)){
                cout<<dx<<' '<<dy<<endl;
                return 0;
            }
        }
    }
}