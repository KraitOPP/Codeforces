#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        string s1,s2;
        cin>>n>>s1>>s2;
        bool isone=false,flag=true;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                int src = s1[i]-'0';
                int tar = s2[i]-'0';
                if(src^src == tar){
                    if(tar==1) isone=true;
                }
                else if(isone==false){
                    flag=false;
                    break;
                }
            }
            if(s1[i]=='1') isone=true;
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}