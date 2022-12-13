#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
    int N;
    cin>>N;
    int X,Y;
    cin>>X>>Y;
    vector<vector<int>> dist(N+1,vector<int>(N+1));
    for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++){
        dist[i][j]=min(abs(i-j),abs(i-X)+1+abs(j-Y));
    }
    map<int,int> ans;
    for(int i=1;i<=N;i++)for(int j=i+1;j<=N;j++){
        int d=dist[i][j];
        ans[d]++;
    }
    for(int i=1;i<N;i++)cout<<ans[i]<<'\n';
}