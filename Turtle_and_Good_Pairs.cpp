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
        string s;
        cin>>s;
        vector<int> c(26,0);
        for(int i=0;i<n;i++){
            c[s[i]-'a']++;
        }
        int i=0;
        while(i<n){
            for(int j=0;j<26;j++){
                if(c[j]>0){
                    char tmp = 'a'+j;
                    cout<<tmp;
                    c[j]--;
                    i++;
                }
            }
        }
        cout<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}
