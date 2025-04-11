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
        int n,k;
        cin>>n>>k;
        if(k > pow(2,n-1)){
            cout<<-1<<endl;
            continue;
        }

        k--;
        vi res(n-1);

        for(int i=0;i<n-1;i++){
            if(i<64){
                res[i] = (k >> i) & 1;
            }
            else res[i]=0;
        }
        reverse(res.begin(),res.end());
        for(int i=0;i<n-1;i++){
            if(res[i]==0) cout<<i+1<<" ";
        }
        cout<<n<<" ";
        for(int i=n-2;i>=0;i--){
            if(res[i]==1) cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}