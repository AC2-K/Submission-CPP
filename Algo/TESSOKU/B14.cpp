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
    int N,K;
    cin>>N>>K;
    vector<int> A(N/2),B(N-N/2);
    int siz1=A.size();
    int siz2=B.size();
    rep(i,siz1)cin>>A[i];
    rep(i,siz2)cin>>B[i];
    set<int> sum1,sum2;
    rep(bit,1<<siz1){
        int sum=0;
        rep(i,siz1){
            if(bit&(1<<i))sum+=A[i];
        }
        sum1.insert(sum);
    }
    rep(bit,1<<siz2){
        int sum=0;
        rep(i,siz2){
            if(bit&(1<<i))sum+=B[i];
        }
        sum2.insert(sum);
    }
    for(auto s:sum1){
        int s2=K-s;
        if(sum2.find(s2)!=sum2.end()){
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}