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
const string s1="maerd",s2="remaerd",s3="esare",s4="resare";

int main() {
    bool dp[1001001];
    rep(i,1001001)dp[i]=false;
    string s;
    cin>>s;
    int N=s.size();
    const string str[4]={"dream","dreamer","erase","eraser"};
    dp[0]=true;
    rep(i,N){
        if(!dp[i])continue;
        rep(j,4){
            string add=str[j];
            if(i+add.size()<=N&&s.substr(i,add.size())==add)dp[i+add.size()]=true;
        }
    }
    if(dp[N])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}