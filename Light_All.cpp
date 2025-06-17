#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int curr=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(abs(i-curr)>1) break;
                curr=min(curr+2, i+2);
            }
        }
        if(curr>=n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
