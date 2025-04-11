#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<=b;i++)

bool solve(int n,vector<int> &x, vector<int> &p){
    int idx1=0;
    int idx2=n-1;
    //Right Left
    while(idx1<n-1){
        int tmp = x[idx1+1]-x[idx1];
        if(p[idx1]>=tmp) idx1++;
        else break;
    }
    while(idx2>0){
        int tmp = x[idx2]-x[idx2-1];
        if(p[idx2]>=tmp) idx2--;
        else break;
    }
    if((idx2-idx1)<=1) return true;
    
    //Right Right
    int tidx=idx1+1;
    while(tidx<n-1){
        int tmp = x[tidx+1]-x[tidx];
        if(p[tidx] >= tmp) tidx++;
        else break;
    }
    if(tidx == n-1) return true;
    
    //Left Left
    tidx=idx2-1;
    while(tidx>0){
        int tmp = x[tidx]-x[tidx-1];
        if(p[tidx] >= tmp) tidx--;
        else break;
    }
    if(tidx == 0) return true;
    
    //Left Right
    idx1=1;
    idx2=n-2;
    while(idx1<n){
        int tmp = x[idx1]-x[idx1-1];
        if(p[idx1]>=tmp) idx1++;
        else break;
    }
    idx1--;
    while(idx2>=0){
        int tmp = x[idx2+1]-x[idx2];
        if(p[idx2]>=tmp) idx2--;
        else break;
    }
    idx2++;
    if((idx2-idx1)<=1) return true;    
    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        vector<int> x(n);
        vector<int> p(n);
        loop(i,0,n-1) cin>>x[i];
        loop(i,0,n-1) cin>>p[i];
        
        if(solve(n,x,p)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}