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
    int n;
    cin>>n;
    vector<P> tmp;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        tmp.emplace_back(b,a);
    }
    sort(all(tmp));
    vector<int> L(n),R(n);
    rep(i,n){
        L[i]=tmp[i].second;
        R[i]=tmp[i].first;
    }
    int now=0;
    int ans=0;
    rep(i,n){
        if(L[i]>=now){
            ans++;
            now=R[i];
        }
    }
    cout<<ans<<endl;
}