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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        int res=LLONG_MAX;
        for(int i=0;i<n;i++){
            cin>>a[i];
            res=min(res,a[i]);
        }
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++) res=min(res,a[i]-a[i-1]);
        if(k>2) cout<<0<<endl;
        else if(k==1) cout<<res<<endl;
        else{
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    int diff = a[j]-a[i];
                    res=min(res,diff);
                    int pos = lower_bound(a.begin(),a.end(),diff)-a.begin();
                    if(pos<n) res=min(res,a[pos]-diff);
                    if(pos-1>=0) res=min(res,diff-a[pos-1]);
                }
            }
            cout<<res<<endl;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}