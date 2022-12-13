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
using P = pair<ll, ll>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N,W;
    cin>>N>>W;
    map<int,int> cnt;
    vector<int> w(N),v(N);
    rep(i,N){
        cin>>w[i]>>v[i];
    }
    vector<P> P1,P2,P3,P4;
    rep(i,N){
        if(w[i]==w[0])P1.push_back(make_pair(v[i],w[i]));
        else if(w[i]==w[0]+1)P2.push_back(make_pair(v[i],w[i]));
        else if(w[i]==w[0]+2)P3.push_back(make_pair(v[i],w[i]));
        else if(w[i]==w[0]+3)P4.push_back(make_pair(v[i],w[i]));
    }
    auto cmp=[&](P a,P b){
        ll va=a.first,wa=a.second;
        ll vb=b.first,wb=b.second;
        //va/wa<vb/wb
        if(1ll*wb*va==1ll*vb*wa)return wa<wb;
        else 1ll*wb*va>1ll*vb*wa;
    };
    sort(all(P1),cmp);
    sort(all(P2),cmp);
    sort(all(P3),cmp);
    sort(all(P4),cmp);

    ll ans=0;
    rep(p1,P1.size())rep(p2,P2.size())rep(p3,P3.size())rep(p4,P4.size()){
        ll wsum=0,vsum=0;
        rep(i,p1){
            wsum+=P1.second;
            vsum+=P1.first;
        }
        
        rep(i,p2){
            wsum+=P2.second;
            vsum+=P2.first;
        }
        
        rep(i,p3){
            wsum+=P3.second;
            vsum+=P3.first;
        }
        
        rep(i,p4){
            wsum+=P4.second;
            vsum+=P4.first;
        }

        if(wsum<=W)ans=max(ans,vsum);
    }
    cout<<ans<<endl;
}