#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    inp(a,n);
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(max(a[0],a[1]));
    for(int i=2;i<n;i+=2){
        if(min(a[i], a[i+1])>pq.top()){
            pq.pop();
            pq.push(a[i]);
            pq.push(a[i+1]);
        }
        else{
            pq.push(max(a[i],a[i+1]));
        }
    }
    int res=0;
    while(!pq.empty()){
        res+=pq.top();
        pq.pop();
    }

    cout<<res<<endl;
    return 0;
}