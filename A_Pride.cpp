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
    int n;
    cin>>n;
    int cnt1=0,odd=0,gc=0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        gc=__gcd(a[i],gc);
        odd+=a[i]%2;
        if(a[i]==1) cnt1++;
    }

    if(gc!=1 || odd==0){
        cout<<-1<<endl;
    }
    else if(cnt1!=0){
        cout<<n-cnt1;
    }
    else{
        int mn=n;
        for(int i=0;i<n;i++){
            int gc=a[i];
            for(int j=i+1;j<n;j++){
                gc = __gcd(gc,a[j]);
                if(gc==1){
                    mn=min(mn,j-i);
                    break;
                }
            }
        }
        // cout<<mn<<" ";
        cout<<n-1+mn<<endl;
    }
    

    return 0;
}