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
    int D,N;
    cin>>D>>N;
    vector<int> T(D+1);
    rep(i,D){
        cin>>T[i+1];
    }
    vector<int> A(N),B(N),C(N);
    rep(i,N){
        cin>>A[i]>>B[i]>>C[i];
    }
    vector<vector<int>> dp(D+1,vector<int>(N,0));     //@dp[i][j]=i日目について、服jを選ぶとする。
    for(int i=1;i<D;i++){
        for(int j=0;j<N;j++){
            if(A[j]>T[i+1]||T[i+1]>B[j])continue;

            for(int _j=0;_j<N;_j++){
                if(A[_j]<=T[i]&&T[i]<=B[_j])chmax(dp[i+1][j],dp[i][_j]+abs(C[j]-C[_j]));
            }
        }
    }
    int ans=0;
    rep(s,N){
        if(A[s]<=T[D]&&T[D]<=B[s])chmax(ans,dp[D][s]);
    }
    cout<<ans<<endl;
}