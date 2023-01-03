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
/*
@A:圧縮したい列
@B:圧縮したあとの列
*/
void comless(vector<int> A,vector<int>&B){
    vector<int> T;
    rep(i,A.size())T.push_back(A[i]);
    sort(all(T));
    T.erase(unique(all(T)),T.end());    //重複消去
    rep(i,A.size()){
        int pos=lower_bound(all(T),A[i])-T.begin();
        B.push_back(pos+1);
    }
}
int main() {
    int N;
    cin>>N;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    vector<int> B;
    comless(A,B);
    for(auto b:B)cout<<b<<' ';
    cout<<endl;
}