#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int calcAnd(int a, int b) {
      int shiftcount = 0;

      while(a != b and a > 0) {
          shiftcount++;
          a = a >> 1; 
          b = b >> 1;
    }
      return int64_t(a << shiftcount);
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,x;
        cin>>n>>x;
        int res=-1;
        int s=n,e=5*1e18;

        while(s<=e){
            int mid = s+(e-s)/2;
            int rangeAnd = calcAnd(n,mid);

            if(rangeAnd==x){
                res=mid;
                e=mid-1;
            }
            else if(rangeAnd > x){
                s=mid+1;
            }
            else e=mid-1;
        }

        cout<<res<<endl;

        // cout<<calcAnd(12,15)<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}