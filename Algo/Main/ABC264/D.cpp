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
int main() {
    string s;
    cin>>s;
    const string tag="atcoder";
    int n=s.size();
    map<string,int> mp;
    queue<string> que;
    mp[s]=0;
    que.push(s);
    while(!que.empty()){
        string t=que.front();que.pop();
        if(t==tag){
            cout<<mp[t]<<endl;
            return 0;
        }
        rep(i,n-1){
            string nex=t;
            swap(nex[i],nex[i+1]);
            if(mp.find(nex)!=mp.end())continue;
            mp[nex]=mp[t]+1;
            que.push(nex);
        }
    }
}