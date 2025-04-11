#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

void solve(string s, int n, int k){
    for(int i=0;i<k;i++){
        bool isOne=false,isZero=false;
        for(int j=i;j<n;j+=k){
            if(s[j]=='1') isOne=true;
            if(s[j]=='0') isZero=true;

            if(isOne && isZero){
                cout<<"NO"<<endl;
                return;
            }
        }
        for(int j=i;j<n;j+=k){
            if(isOne) s[j]='1';
            else if(isZero) s[j]='0';
        }
    }
    int cnt0=0,cnt1=0,cntq=0;
    for(int i=0;i<k;i++){
        if(s[i]=='0') cnt0++;
        else if(s[i]=='1') cnt1++;
        else cntq++;
    }
    if(min(cnt0,cnt1)+cntq < max(cnt0,cnt1)){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    return;
}

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
        string s;
        cin>>s;
        solve(s,n,k);


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}