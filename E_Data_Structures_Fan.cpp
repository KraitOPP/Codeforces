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
        int n;
        cin>>n;
        vector<int> a(n);
        int x0=0,x1=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        string s;
        cin>>s;
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]^a[i];
            if(s[i]=='0') x0^=a[i];
            else x1^=a[i];
        }
        int q;
        cin>>q;
        while(q--){
            int g;
            cin>>g;
            if(g==2){
                int x;
                cin>>x;
                if(x==0) cout<<x0<<" ";
                else cout<<x1<<" ";
            }
            else{
                int l,r;
                cin>>l>>r;
                x0=x0^(pre[r]^pre[l-1]);
                x1=x1^(pre[r]^pre[l-1]);
            }
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}