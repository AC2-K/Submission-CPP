#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
void chmin(ll&x,ll y){x=min(x,y);}
int main() {
    int N;
    cin>>N;
    set<ll> diff;
    for(int pow=1;pow<=N;pow*=6)diff.insert(pow);
    for(int pow=1;pow<=N;pow*=9)diff.insert(pow);

    vector<ll> dp(N+1,INFL);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=N;i++){
        for(auto d:diff){
            if(i-d>=0&&dp[i-d]<INFL)chmin(dp[i],dp[i-d]+1);
        }
    }
    cout<<dp[N]<<endl;
}