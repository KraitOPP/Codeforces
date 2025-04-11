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
        int n;
        cin>>n;
        int x1=2*n-1;
        int x2=n+1;
        int y1=n;
        int y2=2;
        int f1=0;
        int f2=1;
        for(int i=1;i<=n;i++){
            if(i%2){
                if(f2){
                    cout<<x1<<" ";
                    x1-=2;
                }
                else{
                    cout<<x2<<" ";
                    x2+=2;
                }
                f2=!f2;
            }
            else{
                if(f1){
                    cout<<y1<<" ";
                    y1-=2;
                }
                else{
                    cout<<y2<<" ";
                    y2+=2;
                }
                f1=!f1;
            }
        }
        cout<<endl;
        y1=n-1;
        y2=1;
        x1=2*n;
        x2=n+2;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                if(f2){
                    cout<<x2<<" ";
                    x2+=2;
                }
                else{
                    cout<<x1<<" ";
                    x1-=2;
                }
                f2=!f2;
            }
            else{
                if(f1){
                    cout<<y1<<" ";
                    y1-=2;
                }
                else{
                    cout<<y2<<" ";
                    y2+=2;
                }
                f1=!f1;
            }
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}