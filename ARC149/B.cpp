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
using namespace std;
int LIS(vector<int> a){
    int n=a.size();
    vector<int> l(n+1);
    vector<int> dp(n);
    int len=0;
    rep(i,n){
        dp[i]=1;
        int pos=lower_bound(l.begin()+1,l.begin()+len+1,a[i])-l.begin();
        dp[i]=pos;
        l[dp[i]]=a[i];
        if(dp[i]>len)len++;
    }
    return len;
}
int main() {
    int N;
    cin>>N;
    vector<P> a(N);
    rep(i,N){
        cin>>a[i].first;
    }
    rep(i,N){
        cin>>a[i].second;
    }
    sort(all(a));
    vector<int> A(N),B(N);
    rep(i,N)A[i]=a[i].first,B[i]=a[i].second;
    cout<<N+LIS(B)<<endl;
};