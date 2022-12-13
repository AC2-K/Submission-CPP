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
    int N,C;
    cin>>N>>C;
    int M=-1;
    vector<int> a(N),b(N),c(N);
    for(int i=0;i<N;i++){
        cin>>a[i]>>b[i]>>c[i];
        M=max(M,b[i]);
    }
    M+=10;
    vector<vector<int>> dif(N,vector<int>(M));
    for(int i=0;i<N;i++){
        dif[i][a[i]]+=c[i];
        dif[i][b[i]]-=c[i];
    }   
    vector<vector<int>> column(N+1,vector<int>(M+1));
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)column[i][j+1]=column[i][j]+dif[i][j];
    }
}