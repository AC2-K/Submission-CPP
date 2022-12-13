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
    int N,K,Q;
    cin>>N>>K>>Q;
    vector<int> field(N+1,-1);
    vector<int> A(N+1);
    rep(i,K){
        int a;
        cin>>a;
        field[a]=i+1;
        A[i+1]=a;
    }
    rep(i,Q){
        int L;
        cin>>L;
        int pos=A[L];
        if(pos==N)continue;
        if(field[pos+1]==-1){
            A[L]=pos+1;
            field[pos]=-1;
            field[pos+1]=L;
        }
    }
    rep(i,K)cout<<A[i+1]<<'\n';
}