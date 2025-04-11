#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(long long i=a;i<b;i++)

bool isPossible(vector<long long> a, long long n, long long c, long long mid){
    long long sum=0;
    mid=mid*2;
    for(long long i=0;i<n;i++){
        sum+=(a[i]+mid)*(a[i]+mid);
        if(sum>=c) return true;
    }

    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        long long n,c;
        cin>>n>>c;
        vector<long long> a(n);
        for(long long i=0;i<n;i++) cin>>a[i];
        long long s=1;
        long long e=1e9;
        long long ans=0;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(isPossible(a,n,c,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}