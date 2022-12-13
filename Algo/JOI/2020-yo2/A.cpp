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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int N,A;
    cin>>N>>A;
    string S;
    cin>>S;
    ll l=A-1,r=A-1,pos=A-1,dir=1,cnt=0,ans=0;
    rep(i,S.size()){
        if(S[i]=='#')cnt++;
    }
    while(cnt>0){
        if(dir==1){
            ans++;
            pos++;
            if(pos<N)r=pos;
            if(pos==N){
                dir*=-1;
                if(cnt>0){
                    ans+=abs(l-pos);
                    pos=l;
                }
            }else if(S[pos]=='#'){
                dir*=-1;
                cnt--;
                S[pos]='.';
                if(cnt>0){
                    ans+=abs(l-pos);
                    pos=l;
                }
            }
        }
        else{
            ans++;
            pos--;
            if(pos>=0)l=pos;
            if(pos==-1){
                dir*=-1;
                if(cnt>0){
                    ans+=abs(r-pos);
                    pos=r;
                }
            }else if(S[pos]=='#'){
                dir*=-1;
                cnt--;
                S[pos]='.';
                if(cnt>0){
                    ans+=abs(r-pos);
                    pos=r;
                }
            }
        }
    }
    cout<<ans<<endl;
    
}