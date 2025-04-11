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
        string s;
        cin>>s;
        int idx=-1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                idx=i;
                break;
            }
        }
        if(idx!=-1){
            char toinsert = 'a'+((s[idx]-'a'+1)%26);
            s.insert(idx, 1, toinsert);
        }
        else{
            char toinsert = 'a'+((s[0]-'a'+1)%26);
            s.insert(0, 1, toinsert);
        }
        cout<<s<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}
