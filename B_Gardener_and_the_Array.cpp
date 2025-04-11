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
        map<int,int> mp;
        bool f2=false;
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            vector<int> tmp;
            tmp.push_back(k);
            for(int i=0;i<k;i++){
                int x;
                cin>>x;
                mp[x]++;
                tmp.push_back(x);
            }
            a.push_back(tmp);
        }

        for(int i=0;i<n;i++){

            int q=0;
            int k=a[i][0];
            for(int  j=0;j<k;j++){
                int x = a[i][j+1];
                if(mp[x]>=2) q++;
            }
            if(q == a[i][0]){
                f2=true;
            }
        }


        if(f2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}