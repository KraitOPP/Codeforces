#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end(), greater<int>());
    for(int i=0;i<2*n;i+=2){
        if(a[i]!=a[i+1] || (i>0 && a[i]==a[i-1])){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(a[0]%(2*n)!=0){
        cout<<"NO"<<endl;
        return;
    }
    int prv=a[0]/(2*n);
    int cnt=2*(n-1);
    set<int> st;
    st.insert(prv);
    for(int i=0;i<2*n-2;i+=2){
        if(a[i+2]<=0 || a[i]==a[i+2]){
            cout<<"NO"<<endl;
            return;
        }
        int x = (a[i]-a[i+2]);
        if(x%cnt!=0){
            cout<<"NO"<<endl;
            return;
        }
        int y = prv - x/cnt;
        if(y<=0 || st.find(y)!=st.end()){
            cout<<"NO"<<endl;
            return;
        }
        st.insert(y);
        prv=y;
        cnt-=2;
    }

    cout<<"YES"<<endl;
    return;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}