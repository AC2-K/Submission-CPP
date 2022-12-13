#include<bits/stdc++.h>
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
int main() {
    int N;
    cin>>N;
    vector<int> x(N),y(N);
    rep(i,N)cin>>x[i]>>y[i];
    int distMax=0;
    rep(i,N)rep(j,N){
        if(i==j)continue;
        int dx=x[i]-x[j];
        int dy=y[i]-y[j];
        int dist=dx*dx+dy*dy;
        distMax=max(distMax,dist);
    }
    double ans=sqrt(distMax);
    cout<<setprecision(10);
    cout<<ans<<endl;
}