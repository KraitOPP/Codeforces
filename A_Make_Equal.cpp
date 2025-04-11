#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

int solve(vector<int> &h, int n, int m, int mid){
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        int x = h[i];
        int cnt=0;
        while(x/2 >= mid){
            x/=2;
            cnt++;
        }
        cnt+=abs(x-mid);
        tmp[i]=cnt;
    }
    sort(tmp.begin(),tmp.end());
    int res=0;
    for(int i=0;i<n-m;i++){
        res+=tmp[i];
    }
    return res;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<int> h(n);
        for(int i=0;i<n;i++) cin>>h[i];
        sort(h.begin(),h.end());
        
        map<int , int> mp;
        for(int i = 0; i < n; i++)
        {
            int a = h[i];
            int c = 0;
            while(a >= h[0])
            {
                mp[a] = solve(h , n , m , a);
                a = a / 2;
            }
        }

        int ans = 1e9;
        for(auto it : mp)
        {
            ans = min(ans , it.second);
        }
        cout << ans << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}