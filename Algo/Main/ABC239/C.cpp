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
    vector<int> dx={1,2,-1,-2};
    vector<int> dy={1,2,-1,-2};
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    rep(i,4)rep(j,4)rep(k,4)rep(l,4){
        if(dx[i]*dx[i]+dy[j]*dy[j]!=5)continue;
        if(dx[k]*dx[k]+dy[l]*dy[l]!=5)continue;

        if(x1+dx[i]==x2+dx[k]&&y1+dy[j]==y2+dy[l]){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}