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
    int n;
    cin>>n;
    map<int,vector<int>> mp;
    vi a(n);
    inp(a,n);
    for(int i=0;i<n;i++){
        int col;
        cin>>col;
        if(mp.find(col)==mp.end()){
            mp[col].push_back(a[i]);
        }
        else{
            mp[col].push_back(a[i]+mp[col].back());
        }
    }
    int q, sum=0;
    map<int,int> colrem;
    cin>>q;
    while(q--){
        int typ, col, x;
        cin>>typ>>col>>x;
        if(typ==1){
            sum+=x;
            colrem[col]+=x;
        }
        else{
            int low = 0, high = mp[col].size()-1, res=-1;
            while(low<=high){
                int mid = low+(high-low)/2;
                int val = mp[col][mid] + (mid+1)*(sum - colrem[col]);
                if(val<=x){
                    res=mid;
                    low = mid+1;
                }
                else high = mid-1;
            }

            cout<<res+1<<endl;
        }
    }
    return 0;
}