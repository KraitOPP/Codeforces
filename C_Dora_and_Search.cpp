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
        int mn=1,mx=n;
        int low=-1,high=-1;
        int i=0,j=n-1;
        while(i<j){
            if(low!=-1 && high!=-1) break;
            if(a[i]!=mn && a[i]!=mx){
                low=i;
            }
            else low=-1;
            if(a[j]!=mn && a[j]!=mx){
                high=j;
            }
            else high=-1;
            if(a[i]==mn){
                mn++;
                i++;
            }
            else if(a[i]==mx){
                mx--;
                i++;
            }
            if(a[j]==mx){
                mx--;
                j--;
            }
            else if(a[j]==mn){
                mn++;
                j--;
            }
        }
        if(low!=-1 && high!=-1) cout<<low+1<<" "<<high+1<<endl;
        else cout<<"-1"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}