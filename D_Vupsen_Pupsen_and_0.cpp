#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
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
        int n;
        cin>>n;
        vi a(n);
        inp(a,n);
        if(n%2==0){
            for(int i=0;i<n;i+=2){
                cout<<-a[i+1]<<" "<<a[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        for(int i=0;i<n-3;i+=2){
            cout<<-a[i+1]<<" "<<a[i]<<" ";
        }
        if(a[n-3]*a[n-2]>0){
            cout<<a[n-1]<<" "<<a[n-1]<<" "<<-(a[n-2]+a[n-3])<<endl;
        }
        else if(a[n-2]*a[n-1]>0){
            cout<<-(a[n-2]+a[n-1])<<" "<<a[n-3]<<" "<<a[n-3]<<endl;
        }
        else{
            cout<<a[n-2]<<" "<<-(a[n-3]+a[n-1])<<" "<<a[n-2]<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}