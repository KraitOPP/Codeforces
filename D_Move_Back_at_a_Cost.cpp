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
        int n;
        cin>>n;
        vi a(n);
        multiset<pii> st;
        for(int i=0;i<n;i++){
            cin>>a[i];
            st.insert({a[i],i});
        }
        int curridx=0;
        while(!st.empty()){
            auto itr = st.begin();
            int num = itr->first;
            int idx = itr->second;
            st.erase(itr);
            if(curridx<=idx){
                cout<<num<<" ";
                curridx=idx;
            }
            else st.insert({num+1,n});
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}