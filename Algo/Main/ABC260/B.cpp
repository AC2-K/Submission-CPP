#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
//#include<atcoder/all>	
//using namespace atcoder;  
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);

template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
int main() {
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    vector<P> a(n),b(n),c(n);
    rep(i,n){
        int s;
        cin>>s;
        a[i]=make_pair(s,n-i);
    }
    rep(i,n){
        int s;
        cin>>s;
        b[i]=make_pair(s,n-i);
        c[i]=make_pair(a[i].first+b[i].first,n-i);
    }
    vector<int> conf(n,false);
    sort(all(a),greater<>());
    sort(all(b),greater<>());
    sort(all(c),greater<>());
    rep(j,n){
        int i=n-a[j].second;
        if(x<=0)continue;
        if(conf[i])continue;
        x--;
        conf[i]=true;
    }
    rep(j,n){
        int i=n-b[j].second;
        if(y<=0)continue;
        if(conf[i])continue;
        y--;
        conf[i]=true;
    }
    rep(j,n){
        int i=n-c[j].second;
        if(z<=0)continue;
        if(conf[i])continue;
        z--;
        conf[i]=true;
    }
    rep(i,n){
        if(conf[i])cout<<i+1<<'\n';
    }
}