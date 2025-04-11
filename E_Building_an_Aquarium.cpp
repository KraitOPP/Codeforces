#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for (int i = a; i < b; i++)

bool isPossible(vector<int> height, int n, int x, int mid){
    int ans=0;
    for (int i=0; i<n; i++){
        ans+=max(0ll,mid-height[i]);
    }

    return ans>=x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        auto begin = chrono::high_resolution_clock::now();

        int n,x;
        cin>>n>>x;
        vector<int> h(n);
        for (int i = 0; i < n; i++){
            cin>>h[i];
        }

        int s=1;
        int e=1e10;
        int ans=0;

        while(s<=e){
            int mid=s+(e-s)/2;
            if (isPossible(h,n,x,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=max(0ll,ans-h[i]);
        }
        if(sum>x) cout<<ans-1<<endl;
        else cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
