#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        string s;
        cin>>n>>s;
        int mxfrq=0, lwfrq=n+1;
        char mxch='\0', lwch='\0';
        vi frq(26,0);
        for(int i=0;i<n;i++){
            frq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(frq[i]==0) continue;
            if(mxfrq<frq[i]){
                mxfrq=frq[i];
                mxch='a'+i;
            }
            if(lwfrq>=frq[i]){
                lwfrq=frq[i];
                lwch='a'+i;
            }
        }
        // cout<<lwch<<" "<<mxch<<endl;
        for(int i=0;i<n;i++){
            if(s[i]==lwch){
                s[i]=mxch;
                break;
            }
        }
        if(lwch==mxch){
            for(int i=0;i<n;i++){
                if(s[i]!=mxch){
                    s[i]=mxch;
                    break;
                }
            }
        }
        cout<<s<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}