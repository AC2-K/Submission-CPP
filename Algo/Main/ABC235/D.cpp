#include <bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
// using namespace atcoder;
// cout << fixed << setprecision(10);
#define rep(i, N) for (int i = 0; i < (N); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll rot(ll t)
{
    string u = to_string(t);
    string _u;
    for (int i = 1; i < u.size(); i++)
        _u.push_back(u[i]);
    _u.push_back(u[0]);
    return stoi(_u);
}
int main()
{
    ll a,N;
    cin>>a>>N;
    map<ll,int> dist;
    queue<ll> que;
    dist[N]=0;
    que.push(N);
    while(!que.empty()){
        ll t=que.front();que.pop();
        if(t==1){
            cout<<dist[t]<<endl;
            return 0;
        }
        ll nex1=rot(t);
        if(to_string(nex1).size()==to_string(t).size()){
            if(dist.find(nex1)==dist.end()&&nex1){
                que.push(nex1);
                dist[nex1]=dist[t]+1;
            }
        }  
        if(t%a==0){
            nex1=t/a;
            if(dist.find(nex1)==dist.end()&&nex1){
                que.push(nex1);
                dist[nex1]=dist[t]+1;
            }
        }
    }
    cout<<-1<<endl;
}