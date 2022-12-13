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
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    rep(i,H)cin>>S[i];
    rep(i,H)rep(j,W){
        if(S[i][j]=='.')continue;
        bool ex=false;
        rep(k,4){
            int ni=i+dx[k],nj=j+dy[k];
            if(ni<0||nj<0||ni>=H||nj>=W)continue;
            if(S[ni][nj]=='#')ex=true;
        }
        if(!ex){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}