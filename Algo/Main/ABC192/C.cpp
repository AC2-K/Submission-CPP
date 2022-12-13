#include<bits/stdc++.h>
using namespace std;
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

int N,K;

ll f(int n){
    string s=to_string(n);
    sort(all(s));
    int g2=stoi(s);
    reverse(all(s));
    int g1=stoi(s);
    return g1-g2;
}
ll a(int n){
    if(n==0)return N;
    else return f(a(n-1));
}
int main() {
    cin>>N>>K;
    cout<<a(K)<<endl;
}