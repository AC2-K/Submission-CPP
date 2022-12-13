#include<bits/stdc++.h>
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
    int N,D;
    cin>>N>>D;
    vector<int> X(N),Y(N);
    rep(i,N)cin>>X[i]>>Y[i];
    vector<bool> finish(N,false);
    int ans=0;
    for(int i=1;i<=D;i++){
        int maxVal=0;
        int workName=-1;
        rep(j,N){
            if(i<X[j])continue;
            if(finish[j])continue;
            if(maxVal<Y[j]){
                maxVal=Y[j];
                workName=j;
            }
        }
        if(workName>=0)finish[workName]=true;
        ans+=maxVal;
    }
    cout<<ans<<endl;
}