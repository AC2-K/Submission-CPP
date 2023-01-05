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
/*
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
*/
const int dx[]={1,1,1,0,0,-1,-1,-1,0};
const int dy[]={1,0,-1,1,-1,1,0,-1,0};
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    map<int,map<int,int>> cnt;
    int h,w;
    cin>>h>>w;
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
        cnt[a[i]][b[i]]++;
    }
    int ans=0;
    rep(i,n){
        rep(ii,9){
            int si=a[i]+dx[ii];
            int sj=b[i]+dy[ii];
            int res=0;
            rep(iii,9){
                int pi=si+dx[iii];
                int pj=sj+dy[iii];
                res+=cnt[pi][pj];
            }
            chmax(ans,res);
        }
    }
    cout<<ans<<endl;
}