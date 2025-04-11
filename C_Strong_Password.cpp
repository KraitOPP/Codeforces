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
        string s;
        cin>>s;
        int m;
        cin>>m;
        string l,r;
        cin>>l>>r;
        int prv=0;
        for(int i=0;i<m;i++){
            char left = l[i],right = r[i];
            int x = prv;
            for(char j=left;j<=right;j++){
                int next = prv;
                while(next<s.size() && s[next]!=j) next+=1;
                x = max(x,next);
            }
            prv = x+1;
        }
        if(prv>s.size()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}