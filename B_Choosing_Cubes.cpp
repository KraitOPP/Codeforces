#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int x,y,k;
        cin>>x>>y>>k;
        int i=0;
        while(i<=k){
            int nxtmov = y-x%y;
            if(x== 1) {
                k=(k-i)%nxtmov;
                x+=k;
                break;
            }
            if(nxtmov+i <= k){
                i+=nxtmov;
                x+=nxtmov;
                while(x%y==0) x/=y;
            }
            else{
                x+=k-i;
                break;
            }
        }
        cout<<x<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}