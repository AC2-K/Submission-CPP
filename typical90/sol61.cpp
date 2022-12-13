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
int main() {
    int Q;
    cin>>Q;
    deque<int> deq;
    rep(i,Q){
        int t;
        cin>>t;
        int x;
        cin>>x;
        if(t==1){
            deq.push_front(x);
        }
        else if(t==2){
            deq.push_back(x);
        }
        else{
            cout<<deq[x-1]<<'\n';
        }
    }
}