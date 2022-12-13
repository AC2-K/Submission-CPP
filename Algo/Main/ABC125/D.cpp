#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
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
    int n;
    cin>>n;
    vector<ll> a(n);
    int neg=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]<0)neg++;
    }
    if(neg%2==0){
        ll sum=0;
        rep(i,n)sum+=abs(a[i]);
        cout<<sum<<endl;
    }
    else{
        ll sub=INFL;
        rep(i,n)sub=min(sub,abs(a[i]));
        
        ll sum=0;
        rep(i,n)sum+=abs(a[i]);
        sum-=2*sub;
        cout<<sum<<endl;
    }
}