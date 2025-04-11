#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

bool solve(vector<int> &x, vector<int> &h, int n, int k){
    int b=-1;
    int hsum=0;
    for(int i=0;i<n;i++){
        hsum+=h[i];
        if(x[i] < hsum){
            b=i;
            break;
        }
    }
    if(b==-1) return true;
    int e=b;
    for(int i=b;i<n;i++){
        int tmp = x[i]-x[b];
        if(tmp<=2*k){
            e=i;
        }
        else break;
    }
    for(int i=b;i<=e;i++) h[i]=0;
    hsum=0;
    for(int i=0;i<n;i++){
        hsum+=h[i];
        if(x[i] < hsum){
            return false;
        }
    }
    
    return true;
}

signed main(){ 
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        vector<int> x(n);
        vector<int> h(n);
        loop(i,0,n) cin>>x[i];
        loop(i,0,n) cin>>h[i];

        if(solve(x,h,n,k)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}