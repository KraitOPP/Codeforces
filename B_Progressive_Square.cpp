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
        int n,c,d;
        cin>>n>>c>>d;
        vector<int> k(n*n);
        loop(i,0,n*n) cin>>k[i];

        vector<vector<int>> a(n,vector<int>(n,0));
        vector<int> b(n*n);
        a[0][0]=0;
        loop(i,0,n){
            loop(j,0,n){
                if((i+1) < n) a[i+1][j] = a[i][j]+c;
                if((j+1) < n) a[i][j+1] = a[i][j]+d;
            }
        }
        int x=0;
        loop(i,0,n){
            loop(j,0,n){
                b[x] = (a[i][j]);
                x++;
            }
        }
        sort(b.begin(),b.end());
        sort(k.begin(),k.end());
        int f=1;
        for(int i=1;i<n*n;i++){
            int d1 = b[i]-b[i-1];
            int d2 = k[i]-k[i-1];
            if(d1!=d2){
                f=0;
                break;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}