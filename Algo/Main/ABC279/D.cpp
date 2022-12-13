#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
#include<cmath>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
ll a,b;

double f(ld x){
    return x*b+a/sqrt(x+1);
}
int main() {
    cout<<fixed<<setprecision(12);
    cin>>a>>b;
    ld ansPoint=pow(a/b/2,ld(2)/3)-ld(1.0000000001);
    double ans=f(0);
    ll ansp=ansPoint;
    cout<<ansp<<endl;
    if(ansp>=0)ans=min(ans,f(ansp));
    if(ansp-1>=0)ans=min(ans,f(ansp-1));
    if(ansp+1>=0)ans=min(ans,f(ansp+1));
    cout<<ans<<endl;
}