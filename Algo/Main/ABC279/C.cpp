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
    int H,W;
    cin>>H>>W;
    vector<string> vec1(W);
    vector<string> vec2(W); 
    rep(i,H)rep(j,W){
        char c;
        cin>>c;
        vec1[j].push_back(c);
    }
    rep(i,H)rep(j,W){
        char c;
        cin>>c;
        vec2[j].push_back(c);
    }
    sort(all(vec1));
    sort(all(vec2));
    if(vec1==vec2){
        cout<<"Yes\n";
        return 0;
    }
    else{
        cout<<"No\n";
        return 0;
    }
}