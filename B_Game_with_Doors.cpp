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
        int l,r;
        cin>>l>>r;
        int L,R;
        cin>>L>>R;
        int x=max(l,L);
        int y=min(r,R);
        if(x>y) cout<<1<<endl;
        else if(x==y) cout<<2<<endl;
        else if(l==x && r==y && L==x && R==y) cout<<r-l<<endl;
        else if(((l==x && r==y) || (L==x && R==y)) && r!=R && l!=L) cout<<min(R-L+2,r-l+2)<<endl;
        else{
            cout<<y-x+1<<endl;
        } 
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}