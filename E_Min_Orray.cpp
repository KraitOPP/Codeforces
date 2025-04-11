#include <bits/stdc++.h>
using namespace std;
#define int long long
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
        int bor=0;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            bor|=a[i];
        }
        int minlen = n;
        int left = 0;

        map<int,int> mp;
        int tmp=bor;
        int bits=0;
        int i=0;
        while(tmp){
            mp[i] = tmp%2;
            bits+=tmp%2;
            tmp/=2;
            i++;
        }
        map<int,int> cmp;
        int cnt=0;
        for (int i=0;i<n; i++) {
            int j=0;
            tmp=a[i];
            while(tmp){
                if(tmp%2==1 && mp[j]!=0){
                    cmp[j]++;
                    if(cmp[j]==1) cnt++;
                }
                tmp/=2;
                j++;
            }
            while (cnt==bits && left<=i) {
                minlen=min(minlen, i-left+1);
                tmp=a[left];
                j=0;
                while(tmp){
                    if(tmp%2==1 && mp[j]!=0){
                        cmp[j]--;
                        if(cmp[j]==0) cnt--;
                    }
                    tmp/=2;
                    j++;
                }
                ++left;
            }
        }
        cout<<minlen<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}