#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

bool isPos(vector<pair<int,int>> &a, int n, int mid){
    int currminPos=0;
    int currmaxPos=0;
    for(int i=0;i<n;i++){
        int l=a[i].first,r=a[i].second;
        currminPos-=mid;
        currmaxPos+=mid;
        currminPos=max(currminPos,l);
        currmaxPos=min(currmaxPos,r);
        if(currminPos>currmaxPos) return false;
    }
    
    return true;
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
        int s=0;
        int e=1e9;
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(isPos(a,n,mid)){
                res=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}