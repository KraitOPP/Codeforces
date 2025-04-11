#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    int t;
    cin >> t;
    
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        
        int n;
        cin >> n;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        priority_queue<int,vector<int>,greater<int>> pq;        
        for(int i = 0; i < n; i++){
            pq.push(a[i]);
            while(!pq.empty() && pq.top() < pq.size()){
                pq.pop();
            }
            int x=pq.size();
            cout<<max(1ll,x)<<" ";
        }
        cout<<endl;

        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
