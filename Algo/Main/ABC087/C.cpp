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
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    vector<int> B(N);
    rep(i,N)cin>>B[i];
    vector<int> sumA(N+1),sumB(N+1);
    rep(i,N)sumA[i+1]=sumA[i]+A[i];
    rep(i,N)sumB[i+1]=sumB[i]+B[i];
    int ans=0;
    for(int i=1;i<=N;i++){
        int sum=sumA[i]+sumB[N]-sumB[i-1];
        ans=max(ans,sum);
    }   
    cout<<ans<<endl;
}