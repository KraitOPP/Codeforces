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
        vector<int> a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        bool isz=0;
        for(int i=0;i<n;i++){
            while(a[i]%10!=0 && a[i]%10!=2){
                a[i]+=a[i]%10;
            }
            if(a[i]%10==0) isz=1;
        }
        bool flg=true;
        if(isz){
            for(int i=1;i<n;i++){
                if(a[i]!=a[i-1]){
                    flg=false;
                    break;
                }
            }
        }
        else{
            for(int i=1;i<n;i++){
                if(abs(a[i]-a[i-1])%20!=0){
                    flg=false;
                    break;
                }
                else if(a[i]%10==0 && a[i]!=a[i-1]){
                    flg=false;
                    break;
                }
            }

        }
        if(flg) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}