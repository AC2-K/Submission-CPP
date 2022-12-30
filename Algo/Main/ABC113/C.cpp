#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}

vector<int> press(vector<P> A){
    vector<int> B;
    vector<P> T;
    rep(i,A.size())T.push_back(A[i]);
    sort(all(T));
    T.erase(unique(all(T)),T.end());    //重複消去
    rep(i,A.size()){
        int pos=lower_bound(all(T),A[i])-T.begin();
        B.push_back(pos+1);
    }
    return B;
}
int main() {
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<P>> city(n+1);
    for(int i=1;i<=m;i++){
        int p,y;
        cin>>p>>y;
        city[p].emplace_back(y,i);
    }
    auto reader=[&](int num)-> string {
        auto ret=to_string(num);
        while(ret.size()<6)ret="0"+ret;
        return ret;
    };
    map<int,string> id;
    for(int i=1;i<=n;i++){
        vector<int> pressed=press(city[i]);
        for(int j=0;j<city[i].size();j++){
            int name=city[i][j].second;
            int rank=pressed[j];
            id[name]=reader(i)+reader(rank);
        }
    }
    for(int i=1;i<=m;i++){
        cout<<id[i]<<endl;
    }
}