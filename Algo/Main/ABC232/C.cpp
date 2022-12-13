#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
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
int main() {
    int N,M;
    cin>>N>>M;
    vector<vector<bool>> G1(N,vector<bool>(N,false));
    vector<vector<bool>> G2(N,vector<bool>(N,false));
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G1[a][b]=true;
        G1[b][a]=true;
    }
    rep(i,M){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        G2[a][b]=true;
        G2[b][a]=true;
    }

    vector<int> P(N);
    rep(i,N)P[i]=i+1;

    //to
    do{
        bool flag=true;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++){
            if(i==j)continue;
            if(G1[i][j]){
                if(!G2[P[i]-1][P[j]-1])flag=false;
            }
            else{
                if(G2[P[i]-1][P[j]-1])flag=false;
            }
        }
        if(flag){
            cout<<"Yes\n";
            return 0;
        }
    }while(next_permutation(all(P)));
    cout<<"No\n";
    return 0;
}