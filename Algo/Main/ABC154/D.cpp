
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
template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
int main() {
    int N,K;
    cin>>N>>K;
    vector<double> E(N);
    rep(i,N){
        double p;
        cin>>p;
        double sum=p*(p+1)/2;
        E[i]=sum/p;
    }
    vector<double> SE(N+1);
    rep(i,N)SE[i+1]=SE[i]+E[i];
    double ans=0;
    for(int l=1;l<=N;l++){
        int r=l+K-1;
        if(r>N)continue;
        chmax(ans,SE[r]-SE[l-1]);
    }
    cout << fixed << setprecision(10);
    cout<<ans<<endl;
}