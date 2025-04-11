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
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pq.push({x,i+1});
        }
        vector<pair<int,int>> res;
        while(pq.size()>=2){
            pair<int,int> a = pq.top();
            pq.pop();
            if(a.first==0) continue;
            pair<int,int> b = pq.top();
            pq.pop();
            if(b.first==0) continue;
            res.push_back({a.second,b.second});
            a.first--;
            b.first--;
            pq.push({a.first,a.second});
            pq.push({b.first,b.second});
        }
        cout<<res.size()<<endl;
        for(auto i:res){
            cout<<i.first<<" "<<i.second<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}