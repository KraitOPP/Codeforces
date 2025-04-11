#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        int a[]={4,7,44,77,47,74,444, 777, 447, 477, 474, 744, 774, 747};
        int f=0;
        loop(i,0,14){
            if((n%a[i])==0){
                f=1;
                break;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}