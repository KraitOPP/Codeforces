#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    freopen("berries.in","r",stdin);
    cin>>n>>k;
    vector<int> a(n);
    int mx=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int res=0;
    for(int i=1;i<=mx;i++){
        vector<int> chunks(i+1,0);
        for(int j=0;j<n;j++){
            chunks[i]+=a[j]/i;
            chunks[a[j]%i]++;
        }
        if(chunks[i] < k/2){
            continue;
        }
        chunks[i]-=k/2;
        int curr=0,tot=0, idx=i;
        while(curr<k/2 && idx>0){
            if(chunks[idx]>0){
                tot+=idx;
                chunks[idx]--;
                curr++;
            }
            else{
                idx--;
            }
        }
        if(curr==k/2){
            res=max(res,tot);
        }
    }

    freopen("berries.out","w",stdout);

    cout<<res<<endl;


    return 0;
}