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
    string S;
    int K;
    cin>>S>>K;
    int N=S.size();
    vector<int> cnt(N+1);
    rep(i,N){
        cnt[i+1]=cnt[i]+(S[i]=='.');
    }
    int ans=-1;
    for(int i=1;i<=N;i++){
        int j=i;
        while(j+1<=N&&cnt[j+1]-cnt[i]<=K){
            j++;
        }
        chmax(ans,j-i+1);
        i=j+1;
    }
    cout<<ans<<endl;
}