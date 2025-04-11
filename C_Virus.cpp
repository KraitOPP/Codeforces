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
        int n,m;
        cin>>n>>m;
        vector<int> inf(m);
        for(int i=0;i<m;i++) cin>>inf[i];
        sort(inf.begin(),inf.end());
        vector<int> gap;
        for(int i=1;i<m;i++){
            gap.push_back(inf[i]-inf[i-1]-1);
        }
        gap.push_back(n-inf[m-1]+inf[0]-1);
        sort(gap.begin(),gap.end(),greater<int> ());
        int res=0,curr=0;
        for(int i=0;i<gap.size();i++){
            if((gap[i]-curr*2)<=0) break;
            res+=gap[i]-curr*2-1;
            if(gap[i]-curr*2-1 == 0) res++;
            curr+=2;
        }
        cout<<n-res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}