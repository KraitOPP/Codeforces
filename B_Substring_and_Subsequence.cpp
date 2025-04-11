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
        string a,b;
        cin>>a>>b;
        int m = a.length();
        int n = b.length();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        int ans = 0;
        for(int i=0;i<n;i++){
            int k=i;
            for(int j=0;j<m;j++){
                if(a[j]==b[k]){
                    k++;
                }
            }
            ans = max(ans,k-i);
        }

        cout<<n+m-ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}