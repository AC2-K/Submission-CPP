#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
int main() {
    string s;
    ll k;
    cin>>s>>k;
    ll cnt=0;
    ll cnt2=0;
    int n=s.size();
    rep(i,n-1)if(s[i]==s[i+1])cnt++;
    if(s[n-1]==s[0])cnt2++;
    cout<<k*cnt+cnt2*(k-1)<<endl;
}