#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
#include<cmath>
using namespace std;
#include<atcoder/all>
using namespace atcoder;
using mint=modint1000000007;
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
    int X,Y;
    cin>>X>>Y;
    if((2*y-x)%3!=0||(2*x-y)%3!=0){cout<<0<<endl;return 0;}
    int x=(2*y-x)/3;
    int y=(2*x-y)/3;
    if(x<0||y<0){cout<<0<<endl;return 0;}
    mint ans=1;
    int a=x+y;
    int b=x;
    for(int i=0;i<b;i++){
        ans*=(a-i);
    }
    for(int i=b;i>=1;i--){
        mint mi=i;
        ans*=mi.inv();
    }
    cout<<ans<<endl;
}