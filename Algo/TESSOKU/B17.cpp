
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
//#include<atcoder/all>	
//using namespace atcoder;  
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

template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
int main() {
    int N;
    cin>>N;
    vector<int> H(N+1);
    for(int i=1;i<=N;i++)cin>>H[i];

    vector<int> dp(N+1,INF);
    dp[1]=0;
    dp[2]=abs(H[1]-H[2]);
    for(int i=1;i<=N;i++){
        if(i+1<=N)chmin(dp[i+1],dp[i]+abs(H[i]-H[i+1]));
        if(i+2<=N)chmin(dp[i+2],dp[i]+abs(H[i]-H[i+2]));
    }
    vector<int> ans;
    int pos=N;
    while(true){
        ans.push_back(pos);
        if(pos==1)break;
        if(dp[pos-1]+abs(H[pos-1]-H[pos])==dp[pos])pos--;
        else pos-=2;
    }
    reverse(all(ans));
    cout<<ans.size()<<endl;
    for(auto a:ans)cout<<a<<' ';
}