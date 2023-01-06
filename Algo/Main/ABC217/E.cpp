#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    queue<int> que;
    priority_queue<int,vector<int>,greater<int>> pque;
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x;
            cin>>x;
            que.push(x);
        }else if(t==2){
            if(pque.empty()){
                cout<<que.front()<<endl;
                que.pop();
            }else{
                cout<<pque.top()<<endl;
                pque.pop();
            }
        }else{
            while(!que.empty()){
                pque.push(que.front());
                que.pop();
            }
        }
    }
}