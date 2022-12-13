#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
using ll = long long;
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
int main() {
    ll N,K,D;
    cin>>N>>K>>D;
    vector<ll> A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    vector<vector<vector<ll>>> dp(N+1,vector<vector<ll>>(K+1,vector<ll>(D,-1)));
    dp[0][0][0]=0;
    for(int i=0;i<N;i++)for(int j=0;j<K+1;j++)for(int k=0;k<D;k++){
        if(dp[i][j][k]==-1)continue;
        chmax(dp[i+1][j][k],dp[i][j][k]);
        if(j+1<=K){
            chmax(dp[i+1][j+1][(k+A[i]%D)%D],dp[i][j][k]+A[i]);
        }  
    }
    if(dp[N][K][0]==-1)cout<<-1<<endl;
    else cout<<dp[N][K][0]<<endl;
}