#include<bits/stdc++.h>
using namespace std;
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

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int a=1;a<n;a++)for(int b=1;b*a<n;b++){
        int c=n-a*b;
        if(c<=0)continue;
        ans++;
    }
    cout<<ans<<endl;
}