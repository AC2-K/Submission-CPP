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
    int Q;
    cin>>Q;
    set<ll> desk,_desk;
    rep(i,Q){
        ll t,x;
        cin>>t>>x;
        if(t==1){
            desk.insert(x);
            _desk.insert(-x);
        }
        else{
            if(desk.empty()){
                cout<<-1<<endl;
                continue;
            }
            ll a=INFL,b=INFL;
            auto itr=desk.lower_bound(x);
            if(itr!=desk.end())a=*itr;
            auto _itr=_desk.lower_bound(-x);
            if(_itr!=_desk.end())b=-(*_itr);
            cout<<min(abs(x-a),abs(x-b))<<endl;
        }
    }
}