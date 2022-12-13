
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
    int N,S;
    cin>>N>>S;
    vector<int> a(N),b(N);
    rep(i,N)cin>>a[i]>>b[i];

    vector<vector<bool>> dp(N+1,vector<bool>(S+1,false));
    dp[0][0]=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<=S;j++){
            if(!dp[i][j])continue;
            if(j+a[i]<=S)dp[i+1][j+a[i]]=true;
            if(j+b[i]<=S)dp[i+1][j+b[i]]=true;
        }
    }
    if(dp[N][S]){
        cout<<"Yes\n";
        int sum=S;
        string ans;
        for(int pos=N-1;pos>=0;pos--){
            if(sum-a[pos]>=0&&dp[pos][sum-a[pos]]){
                ans.push_back('H');
                sum-=a[pos];
            }
            else{
                ans.push_back('T');
                sum-=b[pos];
            }
        }
        reverse(all(ans));
        cout<<ans<<'\n';
    }
    else cout<<"No\n";
}