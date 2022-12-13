#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
//#include<atcoder/all>	  
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);
int main() {
    int N;
    cin>>N;
    vector<ll> A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<ll> d(N+1);
    for(int i=1;i<=N;i++)d[i]=d[i-1]+A[i];
    vector<ll> pos_max(N+1);
    for(int i=1;i<=N;i++){
        pos_max[i]=max(pos_max[i-1],d[i-1]+A[i]);
    }
    ll ans=0;
    ll pos=0;
    for(int i=1;i<=N;i++){
        ans=max(ans,pos+pos_max[i]);
        pos=pos+d[i];
    }
    cout<<ans<<endl;
}