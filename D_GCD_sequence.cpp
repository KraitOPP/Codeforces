#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

bool solve(vector<int> &a, int n){
    int prv=0;
    int idx=-1;
    for(int i=0;i<n-1;i++){
        int tmp = __gcd(a[i],a[i+1]);
        if(tmp<prv){
            idx=i;
            break;
    }
        prv = tmp;
    }
    if(idx==-1) return true;

    int lft = max(0ll,idx-1);
    int rgt = min(n-1,idx+1);
    for(int i=lft;i<=rgt;i++){
        vector<int> tmp = a;
        tmp.erase(tmp.begin()+i);
        int prv=0;
        int idx=-1;
        for(int j=0;j<tmp.size()-1;j++){
            int gd = __gcd(tmp[j],tmp[j+1]);
            if(gd<prv){
                idx=i;
                break;
            }
            prv = gd;
        }
        if(idx==-1) return true;
    }
    return false;
}

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
        vector<int> a(n);
        loop(i,0,n) cin>>a[i];
        if(solve(a,n)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}