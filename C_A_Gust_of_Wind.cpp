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
        string s;
        cin>>s;
        if(s[0]=='0') cout<<-1<<endl;
        else{
            int c0=0;
            for(int i=0;i<n;i++) c0+=(s[i]=='0')? 1:0;
            int mx=c0+1;
            int mn=c0;
            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    cout<<mx<<" ";
                    mx++;
                }
                else{
                    cout<<mn<<" ";
                    mn--;
                }
            }
            cout<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}