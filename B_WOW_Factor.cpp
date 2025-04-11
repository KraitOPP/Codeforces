#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        string s;
        cin>>s;
        int res=0,w=0,wo=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='o') wo+=w;
            else if(i+1<n && s[i]=='v' && s[i+1]=='v'){
                res+=wo;
                w++;
            }
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}