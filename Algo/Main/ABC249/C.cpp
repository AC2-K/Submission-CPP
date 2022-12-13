#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<map>
#include<set>
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
    //bit全探索
    int N,K;
    cin>>N>>K;
    vector<string> S(N);
    rep(i,N)cin>>S[i];
    int ans=0;
    for(int tmp=0;tmp<(1<<N);tmp++){
        bitset<15> bits(tmp);
        map<char,int> vals;
        rep(i,N){
            set<char> ex;
            if(bits.test(i)){
                string s=S[i];
                for(auto c:s)ex.insert(c);
            }
            for(auto e:ex)vals[e]++;
        }
        int just=0;
        for(auto v:vals)if(v.second==K)just++;
        chmax(ans,just);
    }
    cout<<ans<<endl;
}