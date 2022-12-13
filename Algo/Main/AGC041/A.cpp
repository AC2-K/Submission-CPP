#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<iomanip>
#include<limits>
//#include<atcoder/all>	
//using namespace atcoder;  
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

template<typename T>void chmin(T&x,T y){x=min(x,y);}
template<typename T>void chmax(T&x,T y){x=max(x,y);}
int main() {
    ll N,A,B;
    cin>>N>>A>>B;
    if((B-A)%2==0){
        cout<<(B-A)/2<<endl;
        return 0;
    }
    ll move1=0;  //A,Bを左端に寄せる。
    move1+=A-1;  //Aを1に到達させる
    move1++;  //Aが一度負ける
    move1+=(B-A-1)/2;

    ll move2=0;
    move2+=N-B;
    move2++;
    ll posA=A+(N-B);
    move2+=(B-A-1)/2;
    cout<<min(move1,move2)<<endl;
}