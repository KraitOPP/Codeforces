#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

bool isPos(vector<int> &a, int n, int k, int mid){
    int prv=a[0];
    for(int i=1;i<n;i++){
        if((a[i]-prv+1)>mid){
            k--;
            prv=a[i];
        }
    }
    if(k<=0) return false;
    return true;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n,m,k;
        cin>>n>>m>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> b;
        for(int i=1;i<n;i++) b.push_back(a[i]-a[i-1]-1);
        int res=a[n-1]-a[0]+1;
        sort(b.begin(),b.end(),greater<int>());
        for(int i=0;i<k-1;i++) res-=b[i];
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}