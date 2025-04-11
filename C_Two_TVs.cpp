#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

int getPos(vector<int> &indices, int x){
    return lower_bound(indices.begin(),indices.end(), x) - indices.begin();
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<int> indices;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        a.push_back({l,r});
        indices.push_back(l);
        indices.push_back(r+1);
    }
    sort(indices.begin(),indices.end());
    indices.erase(unique(indices.begin(), indices.end()), indices.end());
    vector<int> pre(indices.size()+1,0);
    for(int i=0;i<n;i++){
        int l=a[i].first,r=a[i].second;
        pre[getPos(indices,l)]++;
        pre[getPos(indices,r+1)]--;
    }
    bool flg=true;
    for(int i=1;i<pre.size();i++){
        pre[i] = pre[i]+pre[i-1];
        if(pre[i]>2){
            flg=false;
            break;
        }
    }
    if(flg) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}