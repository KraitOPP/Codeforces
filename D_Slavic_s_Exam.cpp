#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        string s,t;
        cin>>s>>t;
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                s[i]=t[j];
                j++;
            }
            else if(s[i]==t[j]){
                j++;
            }
            if(j==t.length()) break;
        }
        for(int i=0;i<s.length();i++){
            if(s[i]=='?') s[i]='a';
        }
        if(j<t.length()) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}