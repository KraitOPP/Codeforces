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
        inp(a,n);
        vi b(n);
        int mxfrq=0,mxval=-1;
        set<int> st;
        for(int i=1;i<=n;i++) st.insert(i);

        for(int i=0;i<n;i++){
            if(st.find(a[i])!=st.end()){
                cout<<a[i]<<" ";
                st.erase(a[i]);
            }
            else{
                cout<<*st.begin()<<" ";
                st.erase(st.begin());
            }
        }
        cout<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}