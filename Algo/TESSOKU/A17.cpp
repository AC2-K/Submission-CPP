
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
    vector<int> A(N+1);
    vector<int> B(N+1);
    for(int i=2;i<=N;i++)cin>>A[i];
    for(int i=3;i<=N;i++)cin>>B[i];
    vector<int> dp(N+1,INF);
    dp[1]=0;
    dp[2]=A[2];
    for(int i=3;i<=N;i++){
        chmin(dp[i],dp[i-1]+A[i]);
        chmin(dp[i],dp[i-2]+B[i]);
    }
    int place=N;
    vector<int> ans;
    while(true){
        ans.push_back(place);
        if(place==1){
            cout<<ans.size()<<endl;
            reverse(all(ans));
            for(auto v:ans)cout<<v<<' ';
            cout<<endl;
            return 0;
        }
        
        if(dp[place]==dp[place-1]+A[place]){
            place=place-1;
        }
        else if(place>=3&&dp[place]==dp[place-2]+B[place]){
            place=place-2;
        }
    }
}