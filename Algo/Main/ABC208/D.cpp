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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dist(n,vector<int>(n,INF));  //dist[i][j]:=i->jの最短経路長
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        dist[a][b]=c;
    }
    rep(i,n)dist[i][i]=0;
    ll ans=0;
    for(int k=0;k<n;k++){
        for(int v=0;v<n;v++){
            for(int u=0;u<n;u++){
                dist[v][u]=min(dist[v][u],dist[v][k]+dist[k][u]);
            }
        }
        for(int v=0;v<n;v++)for(int u=0;u<n;u++){
            if(dist[v][u]>=INF)continue;
            ans+=dist[v][u];
        }
    }
    cout<<ans<<endl;
}