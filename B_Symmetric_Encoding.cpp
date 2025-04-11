#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n>>s;

        unordered_map<char,int> occ;
        string enc;
        for(int i=0;i<n;i++){
            if(occ[s[i]]==0) enc=enc+s[i];
            occ[s[i]]++;
        }
        sort(enc.begin(),enc.end());
        unordered_map<char,char> dec;
        int n2 = enc.length();
        for(int i=0;i<=(n2-1)/2;i++){
            dec[enc[i]]=enc[n2-1-i];
            dec[enc[n2-1-i]] = enc[i];
        }
        for(int i=0;i<n;i++){
            cout<<dec[s[i]];
        }
        cout<<endl;
    }
    return 0;
}