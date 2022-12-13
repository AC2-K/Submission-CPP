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
    vector<bool> check=makePrimes(100000);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    for(int i=a;i<=b;i++){
        bool exist=false;
        for(int j=c;j<=d;j++){
            int p=i+j;
            if(check[p])exist=true;
        }
        if(!exist){
            cout<<"Takahashi"<<endl;
            return 0;
        }
    }
    cout<<"Aoki"<<endl;
}