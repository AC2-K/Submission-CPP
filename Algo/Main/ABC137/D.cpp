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
    //A[j]+i<=Mなるjであって、B[j]が最大となるものを選ぶ。
    vector<vector<int>> jobs(m+1);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        if(a>m)continue;
        jobs[a].push_back(b);
    }
    priority_queue<int> que;
    int ans=0;
    for(auto jj:jobs){
        for(auto s:jj)que.push(s);
        if(que.empty())continue;
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
}