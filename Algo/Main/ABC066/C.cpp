#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using namespace atcoder;
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
    int N;
    cin>>N;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    bool rev=(N%2==0);
    deque<int> b;
    rep(i,N){
        if(i%2==0)b.push_back(a[i]);
        else b.push_front(a[i]);
    }
    if(rev){
        for(auto itr=b.begin();itr<b.end();itr++)cout<<*itr<<' ';
        cout<<endl;
    }
    else{
        for(auto itr=b.end()-1;itr>=b.begin();itr--)cout<<*itr<<' ';
        cout<<endl;
    }
}