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
        int n,q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        while(q--){
            int diff=0;
            int l,r,k;
            cin>>l>>r>>k;
            for(int i=l-1;i<r;i++) diff+=abs(a[i]-a[i-1]);
            if(diff<=k){
                cout<<0<<endl;
                continue;
            }
            vector<int> tmp;
            tmp.push_back(a[l-1]);
            for(int i=l;i<r;i++){
                if(a[i]!=a[i-1]) tmp.push_back(a[i]);
            }
            int res=0;
            int sz=tmp.size();
            while(true){
                int diff=0;
                for(int i=1;i<sz;i++) diff+=abs(tmp[i]-tmp[i-1]);
                int mnrqop=INT_MAX;
                int mndiff=diff;
                int mnrqop2=INT_MAX;
                bool flag=false;
                for(int i=1;i<sz;i++){
                    int currdiff;
                    currdiff = diff-abs(tmp[i]-tmp[i-1]);
                    int posdiff=0;
                    int rqop = abs(tmp[i]-tmp[i-1]);
                    if((i+1<sz)){
                        currdiff-=abs(tmp[i+1]-tmp[i]);
                        currdiff+=abs(tmp[i+1]-tmp[i-1]);
                    }
                    if(currdiff<=k){
                        mnrqop=min(mnrqop,rqop);
                        flag=true;
                    }
                    else{
                        if(currdiff<=mndiff){
                            mndiff=currdiff;
                            mnrqop2=rqop;
                        }
                    }
                }

                if(flag){
                    res+=mnrqop;
                }
                else{
                    
                }

            }

        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   