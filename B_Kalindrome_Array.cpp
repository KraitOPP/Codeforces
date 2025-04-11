#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

bool solve(vector<int> &a, int n, int x){
    vector<int> tmp;
    for(int i=0;i<n;i++){
        if(a[i]!=x) tmp.push_back(a[i]);
    }

    for(int i=0;i<tmp.size();i++){
        if(tmp[i]!=tmp[tmp.size()-1-i]) return false;
    }
    
    return true;
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
        for(int i=0;i<n;i++) cin>>a[i];
        int prv=-1;
        bool flag = true;
        int i=0,j=n-1;
        while(i<j){
            if(a[i]==a[j]){
                i++,j--;
            }
            else{
                bool f1 = solve(a,n,a[i]); 
                bool f2 = solve(a,n,a[j]); 
                if(f1||f2){
                    flag=true;
                }
                else flag=false;
                break;
            }
        }
        if(flag){
                    cout<<"YES"<<endl;
                }
                else cout<<"NO"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}