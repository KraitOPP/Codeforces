#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int n,q;
        cin>>n>>q;
        vector<int> a(n+1);
        vector<int> prev(n+1);
        int sum=0ll;
        vector<int> firstidx(n+1,-1),firstval(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            prev[i]=a[i];
            firstval[i]=a[i];
            sum+=a[i];
        }
        int secondidx=-1,secondval=0;
        for(int i=0;i<q;i++){
            int t;
            cin>>t;
            int x;
            if(t==1){
                int idx;
                cin>>idx>>x;
                if(secondidx>firstidx[idx]){
                    sum-=secondval;
                }
                else{
                    sum-=firstval[idx];
                }
                sum+=x;
                firstidx[idx]=i;
                firstval[idx]=x;
            }
            else{
                cin>>x;
                secondidx=i;
                secondval=x;
                sum=n*x;
            }
            cout<<sum<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}