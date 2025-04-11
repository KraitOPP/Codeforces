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
        int n,x,m;
        cin>>n>>x>>m;
        int lft=x,rgt=x;
        while(m--){
            int l,r;
            cin>>l>>r;
            if(l<=lft && r>=lft){
                lft=min(lft,l);
            }
            if(l<=rgt && r>=rgt){
                rgt=max(rgt,r);
            }
        }
        cout<<rgt-lft+1<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}