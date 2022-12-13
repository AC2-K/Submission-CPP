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
    int N,K;
    cin>>N>>K;
    vector<int> lens;
    int last,back,front;
    rep(i,N){
        int t;
        cin>>t;
        if(i==0)front=t;
        if(i==N-1)back=t+1;
        if(i!=0){
            lens.push_back(t-last-1);
        }
        last=t;
    }
    sort(all(lens),greater<>());
    int ans=back-front;
    rep(i,K-1){
        ans-=lens[i];
    }
    cout<<ans<<endl;
}