#include<bits/stdc++.h>
using namespace std;
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
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> vec;
    auto dfs=[&](auto f)-> void {
        if(vec.size()>=n){
            for(auto v:vec)cout<<v<<' ';
            cout<<endl;
        }
        else{
            int b=0;
            if(vec.size()>0)b=vec.back();
            for(int i=b+1;i<=m;i++){
                vec.push_back(i);
                f(f);
                vec.pop_back();
            }
        }
    };
    dfs(dfs);
}