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
        int n,k;
        cin>>n>>k;
        string s1,s2;
        cin>>s1>>s2;
        int c1=0,c2=0,cnt=0;;
        for(int i=0;i<n;i++){
            if(s1[i]=='1') c1++;
            if(s2[i]=='1') c2++;
            if(s1[i]!=s2[i]) cnt++;
        }
        if(c1!=c2) cout<<"NO"<<endl;
        else{
            if(cnt/2==k || (n>2 && (cnt/2<=k))) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}