#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
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
    int N,M;
    cin>>N>>M;
    vector<vector<ll>> d(N,vector<ll>(N,INFL));
    rep(i,N)d[i][i]=0;
    int r;
    cin>>r;
    vector<int> R(r);
    rep(i,r){
        cin>>R[i];
        R[i]--;
    }
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        d[a][b]=c;
        d[b][a]=c;
    }

    rep(k,N)rep(i,N)rep(j,N){
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        d[j][i]=d[i][j];
    }
    ll ans=INFL;
    sort(all(R));
    do{
        ll res=0;
        rep(i,r-1){
            res+=d[R[i]][R[i+1]];
        }
        ans=min(ans,res);
    }while(next_permutation(all(R)));
    cout<<ans<<endl;
}