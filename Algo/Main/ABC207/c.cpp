#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
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
int main() {
    int N;
    cin>>N;
    vector<double> X(N),Y(N);
    rep(i,N){
        int t;
        cin>>t;
        cin>>X[i]>>Y[i];
        if(t==3||t==4)X[i]+=0.5;
        if(t==2||t==4)Y[i]-=0.5;
    }
    int ans=0;
    for(int i=0;i<N;i++)for(int j=i+1;j<N;j++){
        int upper=max(X[i],X[j]);
        int lower=min(Y[i],Y[j]);
        if(lower<upper)ans++;
    }
    cout<<ans<<endl;
}