#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main() {
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

        for (int i=0; i<n; i+=2) {
            if (s[i]=='_') {
                if (i==0 || s[i-1]==')') {
                    s[i]='(';
                } else {
                    s[i]=')';
                }
            }
        }
        int res = 0;
        stack<int> st;

        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } 
            else if (s[i] == ')') {
                if (!st.empty()) {
                    res+=i-st.top();
                    st.pop();
                }
            }
        }
        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }

    return 0;
}