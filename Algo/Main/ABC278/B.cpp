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
bool check(int H,int M){
    int h=10*(H/10)+M/10;
    int m=10*(H%10)+M%10;
    if(0<=h&&h<=23&&0<=m&&m<=59)return true;
    return false;
}
int main() {
    int H,M;
    cin>>H>>M;
    int now=H*60+M;
    while(true){
        int h=now/60;
        int m=now%60;
        if(check(h,m)){
            cout<<h<<' '<<m<<'\n';
            return 0;
        }
        now++;
        now%=1440;
    }
}