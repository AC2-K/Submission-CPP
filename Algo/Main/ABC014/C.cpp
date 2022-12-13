#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
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
    int n;
    cin>>n;
    const int M=1000002;
    int imos[M];
    rep(i,n){
        int a,b;
        cin>>a>>b;
        imos[a]++;
        imos[b+1]--;
    }
    int res[M+2];
    res[0]=imos[0];
    for(int i=1;i<=M;i++){
        res[i]=res[i-1]+imos[i];
    }
    int ans=-1;
    rep(i,M)ans=max(ans,res[i]);
    cout<<ans<<endl;
}