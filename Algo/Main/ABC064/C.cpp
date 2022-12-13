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
    int N;
    cin>>N;
    int segment[]={1,400,800,1200,1600,2000,2400,2800,3200,1000000};
    vector<int> check(9);
    rep(_,N){
        int a;
        cin>>a;
        rep(i,9){
            if(segment[i]<=a&&a<segment[i+1])check[i]++;
        }
    }
    int cnt=0;
    rep(i,8)if(check[i]>0)cnt++;
    int minimum=cnt;
    if(cnt==0)minimum=1;

    int maximum=cnt+check[8];
    cout<<minimum<<' '<<maximum<<endl;
}