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
        string a,b;
        int n;
        cin>>n>>a>>b;
        int c0=0,c1=0;
        string s1 = '0'+a;
        string s2 = '0'+b;
        vector<bool> pos(n+1,false);
        for(int i=1;i<=n;i++){
            if(s1[i]=='0') c0++;
            else c1++;

            if(c0==c1) pos[i]=true;
        }
        if(s1==s2){
            cout<<"YES"<<endl;
        }
        else{
            int prv=0;
            for(int i=1;i<=n;i++){
                if(pos[i]){
                    bool flip=false;
                    for(int j=prv+1;j<=i;j++){
                        if((s1[j]=='0' && s2[j]=='1') || (s1[j]=='1' && s2[j]=='0')){
                            flip=true;
                            break;
                        }
                    }
                    if(flip){
                        for(int j=prv+1;j<=i;j++){
                            s1[j]=s1[j]=='0' ? '1' : '0';
                        }
                    }
                    prv=i;
                }
            }
            if(s1==s2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}