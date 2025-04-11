#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n,k,x;
        cin>>n>>k>>x;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a.begin(),a.end());
        vector<int> tmp;
        for(int i=1;i<n;i++){
            if(a[i]-a[i-1]>x){
                int cnt = (a[i] - a[i-1] - 1) / x;                
                tmp.push_back(cnt);
            }
        }
        int grps=tmp.size()+1;
        sort(tmp.begin(),tmp.end());
        for(int i=0;i<tmp.size();i++){
            if(tmp[i]<=k){
                grps--;
                k-=tmp[i];
            }
            else break;
        }
        cout<<grps<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}