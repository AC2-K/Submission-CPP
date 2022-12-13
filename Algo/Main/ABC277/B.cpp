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
    int N;
    cin>>N;
    vector<string> s(N);
    rep(i,N)cin>>s[i];
    bool flag1=true;
    bool flag2=true;
    rep(i,N)rep(j,N){
        if(i==j)continue;
        if(s[i]==s[j])flag2=false;
    }
    rep(i,N){
        if(s[i][0]!='H'&&s[i][0]!='D'&&s[i][0]!='C'&&s[i][0]!='S'){
            flag1=false;
        }
        char c=s[i][1];
        if(c!='A'&&(c<'2'||c>'9')&&c!='T'&&c!='J'&&c!='Q'&&c!='K'){
            flag1=false;
        }
    }
    if(flag1&&flag2){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}