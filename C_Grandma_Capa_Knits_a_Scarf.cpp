#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

int isPos(string s, int n, char c){
    int i=0,j=n-1;
    int cnt=0;
    while(i<j){
        if(s[i]==s[j]) i++,j--;
        else if(s[i]==c) i++,cnt++;
        else if(s[j]==c) j--,cnt++;
        else return n;
    }

    return cnt;
}

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
        int res=n;
        for(int i=0;i<26;i++){
            res=min(res,isPos(s,n,'a'+i));
        }

        if(res==n) cout<<-1<<endl;
        else cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}