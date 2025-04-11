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
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m,l;
        cin>>n>>m>>l;
        vpii h(n), p(m);
        for(int i=0;i<n;i++) cin>>h[i].first>>h[i].second;
        for(int i=0;i<m;i++) cin>>p[i].first>>p[i].second;
        
        int res=0, currp=1;
        int j=0;
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            while(j<m && p[j].first <= (h[i].first-1)){
                pq.push(p[j].second);
                j++;
            }

            int dist = h[i].second-h[i].first+1;
            while(!pq.empty() && dist+1 > currp){
                currp+=pq.top();
                pq.pop();
                res++;
            }
            if(dist+1 > currp){
                res=-1;
                break;
            }
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}