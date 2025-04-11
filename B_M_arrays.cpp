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
        int n,m;
        cin>>n>>m;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            mp[tmp%m]++;
        }
        int res=0;
        if(mp[0]>0) res++;
        if(m%2==0 && mp[m/2]>0) res++;
        for(int i=1;i<m/2;i++){
            if(mp[i]>0 || mp[m-i]>0) res+=1+max(0ll,abs(mp[i]-mp[m-i])-1);
        }


        cout<<res<<endl;
    }
    return 0;
}