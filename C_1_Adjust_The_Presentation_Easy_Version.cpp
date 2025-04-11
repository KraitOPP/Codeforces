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
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m,q;
        cin>>n>>m>>q;
        vi a(n),b(m);
        inp(a,n);
        inp(b,m);
        set<int> st;
        bool flg=true;
        int i=0,j=0;
        while(i<n && j<m){
            if(a[i]!=b[j]){
                if(st.find(b[j])==st.end()){
                    flg=false;
                    break;
                }
            }
            else st.insert(a[i]), i++;
            j++;
        }
        while(j<m){
            if(st.find(b[j])==st.end()){
                flg=false;
                break;
            }
            j++;
        }

        if(flg) cout<<"YA"<<endl;
        else cout<<"TIDAK"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}