#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)


vector<int> divi(int n){
    vector<int> div;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                div.push_back(i);
            else{
                div.push_back(i);
                div.push_back(n/i);
            }
        }
    }

    return div;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        int sm=1;
        vector<int> div=divi(n);
        sort(div.begin(),div.end());
        for(int i=0;i<div.size();i++){
            if(div[i]<=k) sm=div[i];
            else break;
        }
        cout<<n/sm<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}