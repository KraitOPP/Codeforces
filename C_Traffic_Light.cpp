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
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        vector<int> a(n,-1);
        int st=0;
        int idx=-1;
        loop(i,0,n){
            if(s[i]=='g'){
                if(idx==-1) idx=i;
                while(st<=i){
                    a[st] = i-st;
                    st++;
                }
            }
        }
        if(st!=n){
            while(st<=n-1){
                a[st] = n-st+idx;
                st++;
            }
        }
        int ans=0;
        loop(i,0,n){
            if(s[i]==c){
                ans=max(ans,a[i]);
            }
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}