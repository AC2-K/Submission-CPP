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
ll gcd(ll a, ll b) {
    if (a % b == 0)return b;
    else return gcd(b, a % b);
}
int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    int G=0;
    rep(i,N)G=gcd(G,A[i]);
    rep(i,N){
        A[i]/=G;
    }
    int ans=0;
    rep(i,N){
        int &a=A[i];
        while(a%2==0){
            a/=2;
            ans++;
        }
        while(a%3==0){
            a/=3;
            ans++;
        }
        if(a!=1){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;
}