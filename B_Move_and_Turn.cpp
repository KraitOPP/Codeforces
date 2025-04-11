#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        if(n%2==0){
            cout<<(n/2+1)*(n/2+1)<<endl;
        }
        else{
            cout<<2*(n/2+1)*(n/2+2)<<endl;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}