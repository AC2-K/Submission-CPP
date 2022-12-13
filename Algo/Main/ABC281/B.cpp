#include<bits/stdc++.h>
using namespace std;
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
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
bool upper_check(string S){
    char c1=S[0];
    reverse(all(S));
    char c2=S[0];
    return isupper(c1)&&isupper(c2);
}
bool midCheck(string S){
    string T;
    for(int i=1;i<S.size()-1;i++){
        T.push_back(S[i]);
    }
    if(T.size()!=6)return false;
    
    for(auto c:T){
        if('0'<=c&&c<='9')continue;
        return false;
    }
    if(T[0]=='0')return false;
    
    return true;
}
int main() {
    string S;
    cin>>S;
    if(upper_check(S)&&midCheck(S)){
        cout<<"Yes\n";
    }
    else cout<<"No\n";
}