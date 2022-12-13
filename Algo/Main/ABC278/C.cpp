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
    int N;
    cin>>N;
    map<pair<int,int>,int>cnt;
    int Q;
    cin>>Q;
    rep(i,Q){
        int t,a,b;
        cin>>t>>a>>b;
        if(t==1){
            cnt[make_pair(a,b)]=1;
        }
        else if(t==2){
            cnt[make_pair(a,b)]=0;
        }
        else{
            if(cnt[make_pair(a,b)]==1&&cnt[make_pair(b,a)]==1){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    } 
}