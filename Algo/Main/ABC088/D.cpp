#include<bits/stdc++.h>  
#define rep(i, N)  for(ll i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using ld = long double;
using Graph = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll dx[4] = { 1,0,-1,0 };
const ll dy[4] = { 0,1,0,-1 };
//cout << fixed << setprecision(10);
ll H, W;
ll getNum(ll i, ll j) {
	if (i < 0 || j < 0 || i >= H || j >= W)return -1;
	return i * W + j;
}
int main() {
	cin >> H >> W;
	vector<char> F(H * W);
	rep(i, H * W)cin >> F[i];
	vector<ll> dist(H * W, -1);
	dist[0] = 1;
	queue<ll> que;
	que.push(0);
	while (!que.empty()) {
		ll f = que.front();
		que.pop();
		ll now_i = f / W, now_j = f % W;
		rep(i, 4) {
			ll nxt = getNum(now_i + dx[i], now_j + dy[i]);
			if (nxt == -1)continue;
			if (dist[nxt] != -1)continue;
			if (F[nxt] == '#')continue;
			dist[nxt] = dist[f] + 1;
			que.push(nxt);
		}
	}

    ll length=dist[getNum(H-1,W-1)];
    if(length==-1){
        cout<<-1<<endl;
        return 0;
    }
    ll black=0;
    for(auto f:F)if(f=='#')black++;
    cout<<H*W-black-length<<endl;
}