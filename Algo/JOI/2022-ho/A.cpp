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
    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
    }
    vector<ll> leaf;
    vector<ll> piece;
    for(auto&a:A){      //N*log(max(A))
        int size=1;
        while(a%2==0){
            a/=2;
            size*=2;
        }
        leaf.push_back(size);
        piece.push_back(a);
    }
    int n=piece.size();
    vector<ll> cnt(n);
    cnt[0]=leaf[0];
    for(int i=1;i<n;i++){
        cnt[i]=cnt[i-1]+leaf[i];
    }
    int Q;
    cin>>Q;
    while(Q--){
        ll x;
        cin>>x;
        int index=lower_bound(all(cnt),x)-cnt.begin();
        cout<<piece[index]<<endl;
    }
}