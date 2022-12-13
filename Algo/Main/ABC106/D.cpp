#include <bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;
// cout << fixed << setprecision(10);
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> cnt(N + 1, vector<int>(N + 1)); //@cnt[l][r]:区間[l,r]を走る電車の台数
    rep(i, M)
    {
        int l, r;
        cin >> l >> r;
        cnt[l][r]++;
    }
    for(int i=1;i<=N;i++)for(int j=1;j<=N;j++){
        cnt[i][j]+=cnt[i][j-1];
    }
    while(Q--){
        int p,q;
        cin>>p>>q;
        int res=0;
        for(int lefter=p;lefter<=q;lefter++){
            res+=cnt[lefter][q];
        }
        cout<<res<<endl;
    }
}