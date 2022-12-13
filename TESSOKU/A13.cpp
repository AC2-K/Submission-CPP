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
    int N,K;
    cin>>N>>K;
    vector<int> A(N+1);
    for(int i=1;i<=N;i++)cin>>A[i];
    vector<int> R(N);
    for(int i=1;i<N;i++){
        if(i==1)R[i]=1;
        else R[i]=R[i-1];

        while(R[i]<N&&A[R[i]+1]-A[i]<=K)R[i]++;
    }
    ll ans=0;
    for(int i=1;i<N;i++)ans+=R[i]-i;
    cout<<ans<<endl;
}