#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
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
/*
@A:圧縮したい列
@B:圧縮したあとの列
*/
void compress(vector<int> A, vector<int>&B) {
    vector<int> T;
    rep(i, A.size())T.push_back(A[i]);
    sort(all(T));
    T.erase(unique(all(T)), T.end());    //重複消去
    rep(i, A.size()) {
        int pos = lower_bound(all(T), A[i]) - T.begin();
        B.push_back(pos);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    vector<int> b;
    compress(a,b);
    for(auto&bb:b)cout<<bb<<endl;
}