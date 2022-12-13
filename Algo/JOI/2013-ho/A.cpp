#include<bits/stdc++.h>
using namespace std;
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
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    vector<int> vec(n);
    rep(i,n)cin>>vec[i];
    vector<int> len;
    for(int i=0;i<n;){
        int cnt=1;
        int j=i+1;
        for(;j<n&&vec[j]!=vec[j-1];j++){cnt++;}
        i=j;
        len.push_back(cnt);
    }
    int ans=0;
    int siz=len.size();
    if(siz<=3){
        rep(i,siz){
            ans+=len[i];
        }
        cout<<ans<<endl;
        return 0;
    }

    rep(i,siz-2){
        chmax(ans,len[i]+len[i+1]+len[i+2]);
    }
    cout<<ans<<endl;
    return 0;
}