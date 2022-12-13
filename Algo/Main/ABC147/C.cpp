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
    int N;
    cin>>N;
    vector<vector<int>> honest(N),unkind(N);
    rep(i,N){
        int a;
        cin>>a;
        rep(j,a){
            int x,r;
            cin>>x>>r;
            x--;
            if(r==1)honest[i].push_back(x);
            else if(r==0)unkind[i].push_back(x);
        }
    }

    int ans=0;
    int result=0;
    rep(msk,1<<N){
        int cnt=0;
        bool ok=true;
        rep(i,N)if(msk&(1<<i)){
            cnt++;
            for(auto h:honest[i]){
                if(!(msk&(1<<h)))ok=false;
            }
            for(auto u:unkind[i]){
                if(msk&(1<<u))ok=false;
            }
        }
        if(ok){
            if(cnt>ans){
                result=msk;
                ans=cnt;
            }
        }
    }
    cout<<ans<<endl;
}
