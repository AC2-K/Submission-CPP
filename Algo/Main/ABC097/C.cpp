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
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
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
int main() {
    //sのsubstringを列挙して昇順に並べる。この時k番目のは、長さが高々kである。
    //https://naoppy.hateblo.jp/entry/2018/05/13/ABC097/ARC097-C
    string s;
    int k;
    cin>>s>>k;
    set<string> substr;
    for(int i=0;i<s.size();i++){
        for(int len=1;len<=k;len++){
            substr.insert(s.substr(i,len));
        }
    }

    auto itr=substr.begin();
    rep(i,k-1){
        itr++;
    }
    cout<<(*itr)<<endl;
}