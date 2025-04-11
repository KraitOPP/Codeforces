#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    priority_queue<int,vector<int>, greater<int>> pq;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),[&](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;
    });

    int res=0;
    // for(int i=0;i<n;i++){
    //     cout<<a[i].first<<" "<<a[i].second<<endl;
    // }
    for(int i=0;i<k;i++) pq.push(0);
    for(int i=0;i<n;i++){
        if(pq.top()<a[i].first){
            pq.pop();
            pq.push(a[i].second);
            res++;
        }
    }
    cout<<res<<endl;

    return 0;
}