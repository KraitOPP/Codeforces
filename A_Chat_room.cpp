#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

bool solve(string s){
    string h = "hello";
    int j=0;
    int n=s.length();
    loop(i,0,n){
        if(s[i]==h[j]){
            j++;
        }
        if(j==5) return true;
    }
    if(j==5) return true;
    return false;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        string s;
        cin>>s;
        if(solve(s)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    
    return 0;
}