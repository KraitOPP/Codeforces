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
        int c;
        cin>>c;
        vector<pair<int,int>> a;
        for(int i=0;i<c;i++){
            int k;
            cin>>k;
            int heal=0;
            for(int j=0;j<k;j++){
                int tmp;
                cin>>tmp;
                heal=max(heal,tmp-j);
            }
            a.push_back({heal,k});
        }

        sort(a.begin(),a.end());
        int res=0,curr=0;
        for(int i=0;i<c;i++){
            int points = a[i].second;
            int req = a[i].first;

            res=max(res,req-curr);
            curr+=points;
            
        }
        cout<<res+1<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}