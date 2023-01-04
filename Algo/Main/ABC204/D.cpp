#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> t(n);
    for(int i=0;i<n;i++)cin>>t[i];
    int S=0;
    for(int i=0;i<n;i++)S+=t[i];
    //部分和問題を解いておく
    //dp[i][j]:=先頭i項をみる。いくつか選んで和をjにできるか?
    vector<vector<bool>> dp(n+1,vector<bool>(S+1,false));
    dp[0][0]=true;
    for(int i=0;i<n;i++)for(int j=0;j<=S;j++){
        if(!dp[i][j])continue;  //dp[i][j]=falseなら、dp[i][j]からの遷移は起きない

        dp[i+1][j]=true;    //t_iを選ばない場合
        dp[i+1][j+t[i]]=true;   //選ぶ場合
    }
    const int inf=1e9;
    int ans=inf;
    for(int sx=0;sx<=S;sx++){
        if(!dp[n][sx])continue; //作れないならcontinue
        int sy=S-sx;
        int time=max(sx,sy);    //全体でかかる時間
        ans=min(ans,time);
    }
    cout<<ans<<endl;
}