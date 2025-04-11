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
        for(int i=0;i<n;i++) cin>>a[i];
        int i=0,j=n-1;
        int res=0,s1=0,s2=0;
        while(i<=j+1){
            if(s1<s2){
                s1+=a[i];
                i++;
            }
            else if(s1>s2){
                s2+=a[j];
                j--;
            }
            else{
                res=max(res,n-1-j+i);
                s1+=a[i];
                i++;
            }
        }

        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}