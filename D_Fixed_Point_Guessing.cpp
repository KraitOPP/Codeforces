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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int s=1,e=n;
        while(s<e){
            int mid=s+(e-s)/2;
            cout<<"? "<<s<<" "<<mid<<endl;
            int sz = mid-s+1, cnt=0;
            while(sz--){
                int tmp;
                cin>>tmp;
                if(tmp>=s && tmp<=mid) cnt++;
            }
            if(cnt%2==1){
                e=mid;
            }
            else s=mid+1;
        }

        cout<<"! "<<s<<endl;
    }
    return 0;
}