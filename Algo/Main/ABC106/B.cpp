#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
int divcnt(int num){
    set<int> div;
    for(int i=1;i*i<=num;i++){
        if(num%i!=0)continue;
        div.insert(i);
        div.insert(num/i);
    }
    return div.size();
}
int main() {
    int N;
    cin>>N;
    int ans=0;
    for(int n=1;n<=N;n++){
        if(n%2==0)continue;
        if(divcnt(n)==8)ans++;
    }
    cout<<ans<<endl;
}