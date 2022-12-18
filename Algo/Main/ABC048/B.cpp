#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
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
    string S;
    cin>>S;
    int t;
    cin>>t;
    int cnt=0;
    int x=0,y=0;
    for(auto c:S){
        if(c=='L')x++;
        else if(c=='R')x--;
        else if(c=='U')y++;
        else if(c=='D')y--;
        else cnt++;
    }
    
    int dist=abs(x)+abs(y);
    if(t==1){
        chmax(dist,abs(x+cnt)+abs(y));
        chmax(dist,abs(x-cnt)+abs(y));
        chmax(dist,abs(x)+abs(y-cnt));
        chmax(dist,abs(x)+abs(y+cnt));
        cout<<dist<<endl;
    }else{
        int ans=dist-cnt;
        if(ans>=0){
            cout<<ans<<endl;
            return 0;
        }
        while(ans<0)ans+=2;
        ans%=2;
        cout<<ans<<endl;
    }
}