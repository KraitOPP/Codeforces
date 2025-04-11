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
        int n;
        cin>>n;
        vector<int> res;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                n/=i;
                res.push_back(i);
                if(res.size()==2){
                    if(res.back()==n){
                        break;
                    }
                    else{
                        res.push_back(n);
                        break;
                    }
                }
                    
            }
        }
        if(res.size()==3){
            cout<<"YES"<<endl;
            cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<endl;
        }
        else cout<<"NO"<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}