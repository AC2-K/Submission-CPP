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
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
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
long long solve(int n,const vector<ll>&x,const vector<ll>&y,const vector<ll>&p) {
    auto check=[&](ll S)-> bool {
        vector<vector<bool>> g(n,vector<bool>(n,false));
        rep(i,n)rep(j,n){
            if(i==j){
                g[i][j]=true;
            }
            ll dx=abs(x[i]-x[j]);
            ll dy=abs(y[i]-y[j]);
            if(S*p[i]>=dx+dy)g[i][j]=true;
        }
        rep(k,n)rep(i,n)rep(j,n){
            if(g[i][k]&&g[k][j])g[i][j]=true;
        }
        rep(s,n){
            bool fl=true;
            rep(v,n){
                if(!g[s][v]){
                    fl=false;
                }
            }
            if(fl)return true;
        }   
        return false;
    };

    ll ok=4ll*INF;
    ll ng=0;
    while(abs(ng-ok)>1){
        ll mid=ok+(ng-ok)/2;
        if(check(mid))ok=mid;
        else ng=mid;
    }
    return ok;
}
int main(){
    int n;
    cin>>n;
    vector<ll> x(n),y(n),p(n);
    rep(i,n){
        cin>>x[i]>>y[i]>>p[i];
    }
    cout<<solve(n,x,y,p)<<endl;
}