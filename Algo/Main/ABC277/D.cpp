#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
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





struct dsu
{
    //メンバ変数
    //par[x]:=xの親,rank[x]:=xを含む木の高さ,siz[x]:=xを含む木のサイズ(頂点数)
    vector<int> par,rank,siz;
    vector<ll> sum;

    //構造体の初期化
    dsu(int n):par(n,-1),rank(n,0),siz(n,1),sum(n,0){ }

    //メンバ関数
    //root(x):=xが属する木の根,isSame(x,y):=root(x)==root(y)であるか...?,unite(x,y):=xの属する木とyの属する木を併合する,size(x)=xの属する木の根付き木のサイズ
    int root(int x){
        if(par[x]==-1)return x;
        else return par[x]=root(par[x]);
    }

    bool isSame(int x,int y){
        return root(x)==root(y);
    }

    bool unite(int x,int y){
        int rx=root(x),ry=root(y);
        if(rx==ry)return false;

        if(rank[rx]<rank[ry])swap(rx,ry);
        par[ry]=rx;  //大きいほうの木に小さいほうの木をつなぐ

        siz[rx]+=siz[ry];  //根付き木のサイズ調整
        sum[rx]+=sum[ry];
        return true;
    }
    
    int size(int x){
        return siz[root(x)];
    }
    ll treeSum(int x){
        return sum[root(x)];
    }
};
int main() {
    int N,M;
    cin>>N>>M;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    sort(all(A));
    dsu UF(N);
    UF.sum=A;
    rep(i,N){
        int j=(i+1)%N;
        if(A[i]==A[j]||(A[i]+1)%M==A[j])UF.unite(i,j);
    }
    ll erase=0;
    rep(i,N){
        if(UF.root(i)==i){
            erase=max(erase,UF.treeSum(i));
        }
    }
    ll sumA=0;
    rep(i,N)sumA+=A[i];
    cout<<sumA-erase<<endl;
}