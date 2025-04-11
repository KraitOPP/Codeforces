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
        int n,k,q;
        cin>>n>>k>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int i=0,j=0;
        int ans=0;
        while(i<n){
            while (i < n && a[i] > q) i++;
            if (i == n) break;
            j=i;
            while(j<n && a[j]<=q) j++;
            int x = j-i;
            if(x>=k) ans+=((x-k+1)*(x-k+2))/2;
            i = j;
        }
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}