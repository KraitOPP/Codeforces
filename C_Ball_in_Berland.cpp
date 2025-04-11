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
        int a,b,k;
        cin>>a>>b>>k;
        vector<int> by(k);
        vector<int> gi(k);
        map<int,int> boys,girls;
        for(int i=0;i<k;i++){
            cin>>by[i];
            boys[by[i]]++;
        }
        for(int i=0;i<k;i++){
            cin>>gi[i];
            girls[gi[i]]++;
        }
        int res=0;
        for(int i=0;i<k;i++){
            res+=k-boys[by[i]]-girls[gi[i]]+1;
        }
        cout<<res/2<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}