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
        string s;
        cin>>s;
        int n=s.length();

        int ca=0,cb=0;
        int l=0,r=0;
        int mxa=0,mxb=0;

        for(int i=0;i<n;i++){
            if(s[i]=='A') mxa++;
            else mxb++;
        }
        if(mxa%2!=0 || mxb%2!=0){
            cout<<"NO"<<endl;
            return 0;
        }
        
        for(int i=0;i<n;i++){
            if(s[i]=='A') ca++;
            else cb++;
            while((2*ca>mxa || 2*cb>mxb) && l<r){
                if(s[l]=='A') ca--;
                else cb--;
                l++;
            }
            r=i+1;
            if(2*ca==mxa && 2*cb==mxb) break;
        }
        if(2*ca!=mxa && 2*cb!=mxb) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            cout<<l+1<<" "<<r+1<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}