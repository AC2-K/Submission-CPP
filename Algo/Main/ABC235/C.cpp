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
    int N,Q;
    cin>>N>>Q;
    map<int,vector<int>> vec;
    rep(i,N){
        int a;
        cin>>a;
        vec[a].push_back(i+1);
    }
    rep(i,Q){
        int x,k;
        cin>>x>>k;
        if(!vec.count(x)||vec[x].size()<k)cout<<-1<<endl;
        else cout<<vec[x][k-1]<<endl;
    }
}