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
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//???
ll P,Q;
ll mul(ll a,ll b){
    return ((a%P)*(b%P))%P;
}
int main() {
    int N;
    cin>>N;
    cin>>P>>Q;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    rep(i,N)A[i]%=P;
    ll ans=0;
    for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)for(int k=j+1;k<N;k++)for(int l=k+1;l<N;k++)for(int m=l+1;m<N;m++){
        ll prod=1;
        prod=mul(prod,A[i]);
        prod=mul(prod,A[j]);
        prod=mul(prod,A[k]);
        prod=mul(prod,A[l]);
        prod=mul(prod,A[m]);
        if(prod==Q)ans++;
    }
    cout<<ans<<endl;
}