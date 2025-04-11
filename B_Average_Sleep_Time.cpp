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
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        double sum=0;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<k;i++) sum+=a[i];
        double prvweek=sum;
        for(int i=k;i<n;i++){
            int currweek = prvweek+a[i]-a[i-k];
            prvweek=currweek;
            sum+=currweek;
        }
        int num = n-k+1;
        sum=(double)sum/num;
        cout<<fixed <<setprecision(10)<<sum<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}