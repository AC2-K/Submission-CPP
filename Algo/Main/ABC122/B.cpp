#include<bits/stdc++.h>
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
bool checker(string s){
    for(auto c:s)if(c!='A'&&c!='C'&&c!='G'&&c!='T')return false;
    return true;
}
int main() {
    string s;
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)for(int len=s.size();len>0;len--){
        if(i+len-1>=s.size())continue;
        string sub=s.substr(i,len);
        if(checker(sub))ans=max(ans,len);
    }
    
    cout<<ans<<endl;
}