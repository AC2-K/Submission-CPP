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
    vector<int> a(4);
    int sum=0;
    rep(i,4){
        cin>>a[i];
        sum+=a[i];
    }
    rep(tmp,1<<4){
        if(tmp==0)continue;
        int sub=0;
        rep(i,4){
            if(tmp&(1<<i))sub+=a[i];
        }
        if(sub==sum-sub){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}