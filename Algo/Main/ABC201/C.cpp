#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
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
    string s;
    cin>>s;
    int ans=0;
    for(int N=0;N<10000;N++){
        set<int> numbers;
        int n=N;
        rep(i,4){
            numbers.insert(n%10);
            n/=10;
        }
        bool flag=true;
        for(int i=0;i<=9;i++){
            if(numbers.count(i)&&s[i]=='x')flag=false;
            if(!numbers.count(i)&&s[i]=='o')flag=false;
        }
        if(flag)ans++;
    }
    cout<<ans<<endl;
}