#include <bits/stdc++.h>
using namespace std;

#define int long long int

bool ispossible(vector<int> &attack, vector<int> &cool, int h, int mid){
    for(int i=0;i<attack.size();i++){
        h-=((mid+cool[i]-1)/cool[i])*attack[i];
        if(h<=0) return true;
    }

    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();

        int h,n;
        cin>>h>>n;
        vector<int> attack(n);
        vector<int> cool(n);
        for(int i=0;i<n;i++) cin>>attack[i];
        for(int i=0;i<n;i++) cin>>cool[i];
        int s=0,e=1e12;
        int ans=0;
        while(s<=e){
            int mid = (s+e)/2ll;
            if(ispossible(attack,cool,h,mid)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<ans<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }

    return 0;
}
