#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        vector<int> query(q);
        queue<int> qq;
        map<int,int> mp;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<q;i++){
            cin>>query[i];
            if(mp[query[i]]==0) qq.push(query[i]);
            mp[query[i]]++;
        }
        for(int i=0;i<n;i++){
            queue<int> tmp=qq;
            while(!tmp.empty()){
                int top = tmp.front();
                tmp.pop();
                int x=pow(2,top);
                if(a[i]%x==0){
                    a[i]+=x/2;
                }
            }
        }

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}