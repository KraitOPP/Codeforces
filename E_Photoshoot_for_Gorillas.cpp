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
        int n,m,k;
        cin>>n>>m>>k;
        int x;
        cin>>x;
        vector<int> a(x);
        for(int i=0;i<x;i++) cin>>a[i];
        vector<int> rw(n,-1);
        vector<int> cl(m,-1);
        if(k==n){
            for(int i=0;i<n;i++) rw[i]=1;
        } 
        else{
            int s=k-1,e=n-k,mx=n-k+1;
            for(int i=0;i<=s;i++){
                rw[i]=i+1;
            }
            if(s>=e){
                for(int j=n-1;j>=e;j--){
                    if(rw[j]==-1){
                         rw[j]=n-j;
                    }
                    else rw[j]=min(n-j,rw[j]);
                }
            }
            else{
                for(int i=s;i<=e;i++) rw[i]=k;
                for(int i=n-1;i>e;i--) rw[i]=n-i;
            }
            for(int i=0;i<n;i++){
                if(rw[i]>mx) rw[i]=mx;
            }

        }
        if(k==m){
            for(int i=0;i<m;i++) cl[i]=1;
        } 
        else{
            int s=k-1,e=m-k,mx=m-k+1;
            for(int i=0;i<=s;i++){
                cl[i]=i+1;
            }
            if(s>=e){
                for(int j=m-1;j>=e;j--){
                    if(cl[j]==-1){
                        cl[j]=m-j;
                    }
                    else cl[j]=min(m-j,cl[j]);
                }
            }
            else{
                for(int i=s;i<=e;i++) cl[i]=k;
                for(int i=m-1;i>e;i--) cl[i]=m-i;
            }
            for(int i=0;i<m;i++){
                if(cl[i]>mx) cl[i]=mx;
            }
        }
        int res=0;
        sort(a.begin(),a.end(),greater<int>());
        vector<int> pos;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pos.push_back(rw[i]*cl[j]);
            }
        }
        sort(pos.begin(),pos.end(),greater<int>());
        for(int i=0;i<x;i++) res+=pos[i]*a[i];

        cout<<res<<endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}