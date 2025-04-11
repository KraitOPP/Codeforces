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
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(n==3){
            sum-=a[1];
            if(sum%2==0 && (sum/2)==a[1]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else{
            int pos=1;
            if(sum%n!=0){
                cout<<"NO"<<endl;
                continue;
            }
            int mk=sum/n;
            for(int i=1;i<=n-2;i++){
                if(a[i-1]>a[i+1]){
                    a[i+1]+=a[i-1]-mk;
                }
                else{
                    a[i+1]-=mk-a[i-1];
                }
            }
            if(a[n-2]==a[n-1] && a[n-1]==mk) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}