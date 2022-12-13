#include<bits/stdc++.h>
using namespace std;
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
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
	int N,M;
	cin>>N>>M;
	vector<int> A(N+1);
	rep(i,N)cin>>A[i+1];
	vector<int> sums;
	rep(i,N+1)rep(j,N+1){
		sums.push_back(A[i]+A[j]);
	}
	sort(all(sums));
	int ans=0;
	for(auto s:sums){
		int upper=M-s-1;
		auto itr=upper_bound(sums.begin(),sums.end(),upper);
		if(itr==sums.end())continue;
		itr--;
		if(itr==sums.begin())continue;
		int t=*itr;
		if(s+t<=M)ans=max(ans,s+t);
	}
	cout<<ans<<endl;
}