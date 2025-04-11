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
        cin>>n;
        vector<int> a(n);
        vector<int> diff(n,0);
        int prv=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(prv > a[i]){
                diff[i]=prv-a[i];
            }
            else prv=a[i];
        }
        int ans=0;
        int sum=0;
        sort(diff.begin(),diff.end());
        for(int i=0;i<n;i++){
            ans+=(diff[i]-sum)*(n-i+1);
            sum=diff[i];
        }
        cout<<ans<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}