#include<iostream>
#include<vector>
using namespace std;
vector<int> memo,H;
int dp(int i){
    if(memo[i]!=-1)return memo[i];
    int ret=-1;
    if(i==1)return ret=0;
    else if(i==2)return ret=abs(H[2]-H[1]);
    else ret=min(dp(i-1)+abs(H[i]-H[i-1]),dp(i-2)+abs(H[i]-H[i-2]));

    return memo[i]=ret;
}
int main(){
    int N;
    cin>>N;
    memo.assign(N+1,-1);
    H.resize(N+1);
    for(int i=1;i<=N;i++)cin>>H[i];
    cout<<dp(N)<<endl;
}