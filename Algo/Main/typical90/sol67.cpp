#include<bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
ll to10(string N){
    ll pow=1;
    ll ret=0;
    for(int i=N.size()-1;i>=0;i--){
        ret+=1ll*(N[i]-'0')*pow;
        pow*=8ll;
    }
    return ret;
}
string to9(ll N){
    ll pow=1;
    string ret="";
    while(N>0){
        char c=N%9+'0';
        ret=c+ret;
        N/=9;
    }
    return ret;
}
void solve(string &s){
    ll ret=to10(s);
    s=to9(ret);
}
int main() {
    string N;
    cin>>N;
    int K;
    cin>>K;
    rep(i,K)solve(N);
    cout<<N<<'\n';
}