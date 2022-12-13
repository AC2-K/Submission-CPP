#include<iostream>
#include<string>
#include<algorithm>
//#include<atcoder/all>	
//using namespace atcoder;  
#define rep(i, N)  for(int i=0;i<(N);i++)
using namespace std;
int main() {
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int ans=0;
    do{
        for(int i=1;i<s.size();i++){
            string s1,s2;
            for(int j=0;j<s.size();j++){
                if(j<i)s1.push_back(s[j]);
                else s2.push_back(s[j]);
            }
            int num1=stoi(s1);
            int num2=stoi(s2);
            ans=max(ans,num1*num2);
        }
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
}