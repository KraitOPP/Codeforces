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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i%2==1) a[i]*=-1;
        }
        map<int,int> mp;
        int sum=0,flag=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(mp.count(sum)){
                flag=1;
                break;
            }
            mp[sum]++;
        }

        if(flag) cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   