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
        int n;
        cin>>n;
        vi a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        int curr=0, sum=0;
        for(int i=0;i<n;i++){
            if(a[i]%2) curr++;
            sum+=a[i];
            int res=sum-curr/3;
            if(curr%3==1 && (i+1)!=1) res-=1;
            cout<<res<<" ";
            
        }
        cout<<endl;
    }
    return 0;
 }