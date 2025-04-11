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
        int n,x;
        cin>>n>>x;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        for(int i=0;i<n;i++) cin>>c[i];
        int i=0,j=0,k=0;
        int ans=0;
        while(i<n && (a[i]|x)==x){
            ans|=a[i];
            i++;
        }
        while(j<n && (b[j]|x)==x){
            ans|=b[j];
            j++;
        }
        while(k<n && (c[k]|x)==x){
            ans|=c[k];
            k++;
        }
        if(ans==x) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}