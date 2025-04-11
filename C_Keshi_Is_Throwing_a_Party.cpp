#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

bool isPos(vector<pair<int,int>> a,int n,int mid){
    int cnt=0;

    for(int i=0;i<n;i++){
        if(a[i].second >= cnt && a[i].first >= mid-cnt-1){
            cnt++;
        }
    }

    return cnt>=mid;
}

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
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
        int res=0,s=0,e=n;

        while(s<=e){
            int mid = s+(e-s)/2;
            if(isPos(a,n,mid)){
                res=mid;
                s=mid+1;
            }
            else e=mid-1;
        }

        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}