
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
vector<bool> makePrimes(int N) {
    vector<bool> primes(N+1, true);

    primes[0] = primes[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        if (!primes[p]) continue;
        for (int i=2;p*i<=N;i++) {
            primes[p*i] = false;
        }
    }

    return primes;
}
int main() {
    const int M=100000;
    vector<bool> isPrime=makePrimes(M);
    vector<bool> like2017(M+1,false);
    for(int i=3;i<=M;i++){
        if(i%2==0)continue;
        if(isPrime[i]&&isPrime[(i+1)/2])like2017[i]=true;
    }
    vector<int> res(M+1);
    res[0]=0;
    for(int i=1;i<=M;i++){
        if(like2017[i])res[i]=res[i-1]+1;
        else res[i]=res[i-1];
    }
    int Q;
    cin>>Q;
    vector<int> ans;
    rep(i,Q){
        int l,r;
        cin>>l>>r;
        ans.push_back(res[r]-res[l-1]);
    }
    for(auto a:ans)cout<<a<<'\n';
}