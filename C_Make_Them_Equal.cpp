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
        char c;
        cin>>c;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]!=c) cnt++;
        }
        if(cnt==0) cout<<0<<endl;
        else{
            int pos=-1;
            for(int i=1;i<=n;i++){
                bool f=true;
                for(int j=i;j<=n;j+=i){
                    if(s[j-1]!=c){
                        f=false;
                        break;
                    }
                }
                if(f){
                    pos=i;
                    break;
                }
            }
            if(pos!=-1){
                cout<<1<<endl;
                cout<<pos<<endl;
            }
            else{
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}