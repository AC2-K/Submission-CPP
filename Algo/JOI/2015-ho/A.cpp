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
    ll N,M;
    cin>>N>>M;
    vector<ll> P(M);
    rep(i,M){
        cin>>P[i];
        P[i]--;
    }
    vector<ll> A(N),B(N),C(N);
    rep(i,N){
        cin>>A[i]>>B[i]>>C[i];
    }
    vector<ll> imos(N+10);
    rep(i,M-1){
        if(P[i]<P[i+1]){
            imos[P[i]]++;
            imos[P[i+1]]--;
        }
        else{
            imos[P[i+1]]++;
            imos[P[i]]--;
        }
    }
    vector<ll> cnt(N);
    cnt[0]=imos[0];
    rep(i,N-1){
        cnt[i+1]=cnt[i]+imos[i+1];
    } 
    ll ans=0;
    rep(i,N){
        ll c=cnt[i];
        ll cost1=1ll*A[i]*c;
        ll cost2=1ll*(B[i]*c+C[i]);
        ans+=min(cost1,cost2);
    }
    cout<<ans<<endl;
}