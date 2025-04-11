#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

int smallestprimefactor(int n) {
    vector<int> primeFactors;
    while (n % 2 == 0) {
        return 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0) {
            return i;
        }
    }

    return n;
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
        int sm = smallestprimefactor(n);
        int x=n/sm;
        cout<<x*(sm-1)<<" "<<x*(1)<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}