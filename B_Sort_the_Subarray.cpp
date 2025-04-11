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
        vector<int> b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        int l,r;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(a[i]!=b[i]){
                r=i;
                break;
            }
        }
        while(l>0){
            if(b[l-1]<=b[l]) l--;
            else break;
        }
        while(r+1<n){
            if(b[r+1]>=b[r]) r++;
            else break;
        }
        cout<<l+1<<" "<<r+1<<endl;
    }
    return 0;
}