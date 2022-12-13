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
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    //まず、いまそろえたのか調べるためにint xを常に持って置き、setで更新したものを全て入れる。
    set<int> finish;
    rep(i,N)finish.insert(i);
    int Q;
    cin>>Q;
    ll X=0;
    vector<ll> ans;
    rep(i,Q){
        int t;
        cin>>t;
        if(t==1){
            ll _x;
            cin>>_x;
            X=_x;
            finish.clear();     //新たに変更する。
        }
        else if(t==2){
            int pos,x;
            cin>>pos>>x;
            pos--;
            if(finish.find(pos)!=finish.end())A[pos]+=x;    //もし、入れ直してたら普通に足せばいい。
            else{
                A[pos]=X;
                A[pos]+=x;
                finish.insert(pos);
            }
        }
        else{
            int pos;
            cin>>pos;
            pos--;
            if(finish.find(pos)==finish.end())A[pos]=X;
            ans.push_back(A[pos]);
        }
    }
    for(auto a:ans)cout<<a<<'\n';
}