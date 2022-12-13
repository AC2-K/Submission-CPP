#include<iostream>
#include<vector>
//#include<atcoder/all>	  
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()

using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);
int sum[100010];
int R[100010];
int a[100010];
int S(int left,int right){
    //Aの[left,right]の和を求める関数
    return sum[right]-sum[left-1];
}
int main() {
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++)cin>>a[i];
    sum[0]=0;
    for(int i=1;i<=N;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=N;i++){
        if(i==1)R[i]=0;
        else R[i]=R[i-1];

        while(R[i]<N&&S(i,R[i]+1)<=K)R[i]++;
    }
    ll ans=0;
    for(int i=1;i<=N;i++){
        ans+=R[i]-i+1;
    }
    cout<<ans<<'\n';
}