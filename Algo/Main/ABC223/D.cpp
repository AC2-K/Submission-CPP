#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        deg[b]++;
    }
    vector<int> vec;
    priority_queue<int,vector<int>,greater<int>> que;
    for(int v=0;v<n;v++){
        if(deg[v]==0)que.push(v);
    }
    while(!que.empty()){
        int v=que.top();
        que.pop();
        vec.push_back(v);
        for(auto u:g[v]){
            deg[u]--;
            if(deg[u]==0){
                que.push(u);
            }
        }
    }
    if(vec.size()!=n){
        cout<<-1<<'\n';
        return 0;
    }
    for(auto v:vec)cout<<v+1<<' ';
    cout<<'\n';
}