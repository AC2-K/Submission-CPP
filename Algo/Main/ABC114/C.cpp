#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int N;
int flag[M];
void dfs(int C){
  if (C == 3){
    int
  }
  rep(i, N){
    flag[C] = i;
    dfs(C + 1);
  }
}
signed main(){
  cin >> N;
  dfs(0);
}