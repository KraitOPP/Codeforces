#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

bool solve(vector<int> &a, int i, int h){
    vector<int> tmp(a.begin(),a.begin()+i);
    sort(tmp.begin(),tmp.end(),greater<int>());
    int curr=0;
    for(int j=0;j<i;j+=2){
        if(j+1<i) curr+=max(tmp[j],tmp[j+1]);
        else curr+=tmp[j];
        if(curr>h) return false;
    }

    return true;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n,h;
        cin>>n>>h;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int s=1,e=n;
        int res=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(solve(a,mid,h)){
                res=mid;
                s=mid+1;
            }
            else e=mid-1;
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}