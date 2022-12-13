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
    int N;
    cin>>N;
    vector<int> P(N),Q(N);
    rep(i,N)cin>>P[i];
    rep(i,N)cin>>Q[i];
    vector<int> permutation(N);
    rep(i,N)permutation[i]=i+1;
    int a=0,b=0;
    int cnt=0;
    do{
        cnt++;
        if(permutation==P)a=cnt;
        if(permutation==Q)b=cnt;
    }while(next_permutation(all(permutation)));
    cout<<abs(a-b)<<endl;
}