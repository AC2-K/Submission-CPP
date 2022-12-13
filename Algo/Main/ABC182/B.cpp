#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
//#include<atcoder/all>	  
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
int main() {
    int M=0;
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    rep(i,N){
        M=max(M,A[i]);
    }
    int ans=-1;
    int cntMax=0;
    for(int k=2;k<=M;k++){
        int cnt=0;
        rep(i,N){
            if(A[i]%k==0)cnt++;
        }
        if(cntMax<=cnt)ans=k;
        cntMax=max(cnt,cntMax);
    }
    cout<<ans<<endl;
}