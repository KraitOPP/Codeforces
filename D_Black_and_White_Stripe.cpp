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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int st=0,e=k-1;
        int ans=0;
        for(int i=0;i<=k-1;i++){
            if(s[i]=='W') ans++;
        }
        int tmp=ans;
        for(int i=k;i<n;i++){
            if(s[st]=='W') tmp--;
            st+=1;
            e=k;
            if(s[i]=='W') tmp++;
            ans=min(ans,tmp);
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}