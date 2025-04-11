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
bool mp[26];

int calcSc(string &a, string &b){
    int n=a.size();
    int cnt=0,res=0;
    for(int i=0;i<n;i++){
        if(mp[a[i]-'a'] || a[i]==b[i]){
            cnt++;
        }
        else{
            res+=cnt*(cnt+1)/2;
            cnt=0;
        }
    }
    res+=cnt*(cnt+1)/2;

    return res;
}

void solve(string &a, string &b, int idx, int k, int &ans, string &curr){
    if(k==0 || idx==curr.size()){
        ans=max(ans, calcSc(a,b));
        return;
    }

    solve(a,b,idx+1,k,ans, curr);

    mp[curr[idx]-'a']=1;
    solve(a,b,idx+1,k-1,ans, curr);
    mp[curr[idx]-'a']=0;

}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        int res=0;
        set<int> st;
        for(int i=0;i<n;i++) st.insert(a[i]-'a');
        string curr="";
        for(auto c: st){
            curr+=char(c+'a');
        }
        int u=min(k,(int)st.size());
        solve(a,b,0,u,res,curr);
        cout<<res<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}