#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        char prev='0';
        char prv = 'A';
        bool flag=true;
        for(int i=0;i<n;i++){
            if(prv!='A' && (s[i]>='0' && s[i]<='9')){
                flag = false;
                break;
            }
            if((s[i]<='z' && s[i]>='a') && (s[i]<prv)){
                flag=false;
                break;
            }
            if((s[i]<='9' && s[i]>='0') && (s[i]<prev)){
                flag=false;
                break;
            }
            if((s[i]>='a' && s[i]<='z')) prv=s[i];
            else prev = s[i];
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}