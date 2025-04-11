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
        int cnt=0;
        for(int i=0;i<n;i++) cnt+=s[i]=='*';
        int curr=0,idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                curr++;
                if(curr==(cnt+1)/2){
                    idx=i;
                    break;
                }
            }
        }
        curr=cnt/2;
        int pos=idx-1,res=0;
        for(int i=idx-1;i>=0;i--){
            if(s[i]=='*'){
                res+=pos-i;
                pos--;
            }
        }
        pos=idx+1;
        for(int i=idx+1;i<n;i++){
            if(s[i]=='*'){
                res+=i-pos;
                pos++;
            }
        }
        cout<<res<<endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}