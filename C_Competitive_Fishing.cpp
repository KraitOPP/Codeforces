#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define pb push_back
#define po pop_out
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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> pos;
        int sum=0;
        for(int i=n-1;i>0;i--){
            sum+=s[i]=='1' ? 1:-1;
            if(sum>0) pos.pb(sum);
        }
        sort(pos.begin(),pos.end(), greater<int>());
        int i=0, res=1;
        while(k>0 && i<pos.size()){
            k-=pos[i];
            i++;
            res++;
        }
        if(k>0) res=-1;

        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}