#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define rep(i, N)  for(int i=0;i<(N);i++)
using namespace std;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };



struct dsu
{
    //メンバ変数
    //par[x]:=xの親,rank[x]:=xを含む木の高さ,siz[x]:=xを含む木のサイズ(頂点数)
    vector<int> par,rank,siz;

    //構造体の初期化
    dsu(int n):par(n,-1),rank(n,0),siz(n,1){ }

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
        return true;
    }
    
    int size(int x){
        return siz[root(x)];
    }
};
int main() {
    //方針:要するに、'S'の2点であって連結なものが存在すればいい。したがってUnionFindで連結を判定してやる。
    //入力
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    dsu UF(H*W);
    rep(i,H)cin>>S[i];
    auto getId=[&](int i,int j){
        if(i<0||j<0||i>=H||j>=W)return -1;
        return i*W+j;  
    };
    //UnionFindの準備(マージ)
    rep(i,H)rep(j,W){
        rep(k,4){
            int pos=getId(i,j);
            int nxt=getId(i+dx[k],j+dy[k]);
            if(nxt==-1)continue;

            if(S[i][j]=='.'&&S[i+dx[k]][j+dy[k]]=='.')UF.unite(pos,nxt);
        }   
    }
    rep(i,H)rep(j,W)if(S[i][j]=='S'){
        rep(v,4){
            int ni=i+dx[v],nj=j+dy[v];
            int id_n=getId(ni,nj);
            if(id_n==-1)continue;
            rep(u,4){
                int mi=i+dx[u],mj=j+dy[u];
                int id_m=getId(mi,mj);
                if(id_m==-1)continue;
                if(id_m==id_n)continue;
                
                if(UF.isSame(id_n,id_m)){
                    cout<<"Yes\n";
                    return 0;
                }
            }
        }
    }
    cout<<"No\n";
    return 0;
}