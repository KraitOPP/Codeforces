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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> a(n);
        map<int,int> mp;
        mp[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            a[i]=s[i]-'0';
            a[i]-=1;
            sum+=a[i];
            a[i]=sum;
        }
        int res=0;
        for(int i=0;i<n;i++){
            res+=mp[a[i]];

            mp[a[i]]++;
        }

        cout<<res<<endl;



        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   