#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
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
    int N,T;
    cin>>N>>T; 
    int lastPush=-1;
    rep(i,N){
        int t;
        cin>>t;
        lastPush=max(lastPush,t);
        imos[t]++;
        imos[t+T]--;
    }
    vector<int> sums(lastPush+1);
    for(int i=0;i<lastPush;i++){
        sums[i+1]=sums[i]+imos[i+1];
    }
    ll ans=0;
    for(int i=0;i<=lastPush;i++){
        if(sums[i]>0)ans++;
    }
    cout<<ans<<endl;
}