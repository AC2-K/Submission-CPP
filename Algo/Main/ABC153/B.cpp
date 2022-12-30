#include<bits/stdc++.h>
using namespace std;
int main(){
  int H,N;
  cin>>H>>N;
  int S=0;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    S+=a;
  }
  if(S>=H)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}