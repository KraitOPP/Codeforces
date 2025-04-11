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
        string s;
        cin>>s;
        int n=s.length();
        int a1=0;
        int c1=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') c1++;
            else c1=0;
            a1=max(a1,c1);
        }
        int i=0,j=n-1;
        while(i<n && s[i]=='1') i++;
        while(j>=0 && s[j]=='1') j--;
        if(i<=j) a1=max(a1,i+n-1-j);
        int ans=a1;
        if(ans==n) ans=n*n;
        else{
            i=1,j=a1;
            while(i<=j){
                ans=max(ans,i*j);
                i++;
                j--;
            }
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}