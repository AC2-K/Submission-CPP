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
    for(auto&aa:a)cin>>aa;
    int cnt=0;
    for(auto aa:a)if(aa<=0)cnt++;    //マイナスの個数
    if(cnt%2==0){
        ll sum=0;
        for(auto aa:a)sum+=abs(aa);
        cout<<sum<<endl;
    }else{
        ll absMin=INFL;
        for(auto aa:a){
            absMin=min(absMin,abs(aa));
        }
        ll sum=0;
        for(auto aa:a)sum+=abs(aa);
        sum-=2*absMin;
        cout<<sum<<endl;
    }
}