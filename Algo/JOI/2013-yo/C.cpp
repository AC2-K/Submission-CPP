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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int H,W,N;
    cin>>H>>W>>N;
    vector<int> X(N),Y(N);
    rep(i,N){
        cin>>X[i]>>Y[i];
        X[i]--;
        Y[i]--;
    }
    ll ans=0;
    rep(i,N-1){
        int di=X[i+1]-X[i];
        int dj=Y[i+1]-Y[i];
        if(di*dj>=0){
            ans+=max(abs(di),abs(dj));
        }
        else{
            ans+=abs(di)+abs(dj);
        }
    }
    cout<<ans<<endl;
}