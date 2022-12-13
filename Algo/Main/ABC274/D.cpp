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
const int M=100000;
int N,x,y;
int a[1010];
int buf1[2*M+1],buf2[2*M+1],buf3[2*M+1];
int main() {
    cin>>N>>x>>y;
    rep(i,N)cin>>a[i];
    int *dp1=buf1+M;
    int *dp2=buf2+M;
    int *dp3=buf3+M;
    for(int i=-M;i<=M;i++){
        dp1[i]=false;
        dp2[i]=false;
    }
    dp1[a[0]]=true;
    dp2[0]=true;
    for(int i=1;i<N;i++){
        int A=a[i];
        for(int j=-M;j<=M;j++)dp3[j]=false;

        if(i%2==0){
            for(int j=-M;j<=M;j++){
                if(j+A<=M)dp3[j+A]|=dp1[j];
                if(j-A>=-M)dp3[j-A]|=dp1[j];
            }
            swap(dp1,dp3);
        }
        else{
            for(int j=-M;j<=M;j++){
                if(j+A<=M)dp3[j+A]|=dp2[j];
                if(j-A>=-M)dp3[j-A]|=dp2[j];
            }
            swap(dp2,dp3);
        }
    }
    if(dp1[x]&&dp2[y])cout<<"Yes\n";
    else cout<<"No\n";
}