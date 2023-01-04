#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> t(n);
    for(int i=0;i<n;i++)cin>>t[i];
    int sum_t=0;
    for(int i=0;i<n;i++)sum_t+=t[i];
    vector<bool> dp(sum_t+1,false);
    dp[0]=true;
    for(int i=0;i<n;i++)for(int j=0;j<=sum_t;j++){
        if(!dp[j])continue;
        if(j+t[i]<=sum_t)dp[j+t[i]]=true;
        dp[j]=true;
    }
    const int inf=1e9;
    int ans=inf;
    for(int sx=0;sx<=sum_t;sx++){
        if(!dp[sx])continue;
        int sy=sum_t-sx;
        int time=max(sx,sy);
        ans=min(ans,time);
    }
    cout<<ans<<endl;
}