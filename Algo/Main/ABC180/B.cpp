#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<math.h>

#include <iomanip>
#include <limits>
//#include<atcoder/all>	  
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
int N;
ll a[100000];
int main() {
    cin>>N;
    rep(i,N)cin>>a[i];
    ll s=0;
    rep(i,N)s+=a[i]*a[i];
    double d2=sqrt(s);

    ll d1=0;
    rep(i,N)d1+=abs(a[i]);
    
    ll d3=0;
    rep(i,N)d3=max(d3,abs(a[i]));
    cout << fixed << setprecision(10);
    cout<<d1<<'\n'<<d2<<'\n'<<d3<<'\n';
}