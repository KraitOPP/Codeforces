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
        int n,k,b,s;
        cin>>n>>k>>b>>s;
        int req = k*b;
        int rem = s-req;
        int x = (rem+n-1)/n;
        if(x>=k || rem<0) cout<<-1<<endl;
        else{
            int y = rem%n;
            if(y){
                req++;
                y--;
            }
            cout<<req+rem/n<<" ";
            for(int i=1;i<n;i++){
                int tmp = rem/n;
                if(y){
                    tmp++;
                    y--;
                }
                cout<<tmp<<" ";
            }
            cout<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}