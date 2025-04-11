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
        int n,m;
        cin>>n>>m;
        vector<int> a(n,0);
        for(int i=0;i<m;i++){
            int tmp;
            cin>>tmp;
            a[tmp-1]++;
        }
        int s=0,e=2*m;
        int res=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int need=0,extra=0;
            for(int i=0;i<n;i++){
                if(mid>=a[i]){
                    extra+=(mid-a[i])/2;
                }
                else need+=a[i]-mid;
            }
            if(need<=extra){
                res=mid;
                e=mid-1;
            }
            else s=mid+1;
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}