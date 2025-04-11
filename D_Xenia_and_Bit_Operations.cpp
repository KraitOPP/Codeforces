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

void buildSegTree(vi &a, vi &seg, int node, int s, int e, vi &treelvl){
    if(s==e){
        seg[node]=a[s];
        treelvl[node]=1;
        return;
    }
    int mid=(s+e)/2;
    buildSegTree(a,seg,2*node,s,mid,treelvl);
    buildSegTree(a,seg,2*node+1,mid+1,e,treelvl);
    treelvl[node] = 1+treelvl[2*node];
    if(treelvl[node]%2==0){
        seg[node]=seg[2*node]|seg[2*node+1];
    }
    else{
        seg[node]=seg[2*node]^seg[2*node+1];
    }
}

void updateSegTree(vi &seg, int node, int s, int e, int idx, int val, vi &treelvl){
    if(s==e){
        seg[node]=val;
        return;
    }
    int mid=(s+e)/2;
    if(idx<=mid){
        updateSegTree(seg,2*node,s,mid,idx,val,treelvl);
    }
    else{
        updateSegTree(seg,2*node+1,mid+1,e,idx,val, treelvl);
    }
    if(treelvl[node]%2==0){
        seg[node]=seg[2*node]|seg[2*node+1];
    }
    else{
        seg[node]=seg[2*node]^seg[2*node+1];
    }
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int bt,q;
    cin>>bt>>q;
    int n=1<<bt;
    vi a(n);
    inp(a,n);
    vi seg(4*n,-1), treelvl(4*n,-1);
    buildSegTree(a,seg,1,0,n-1,treelvl);
    while(q--){
        int idx, val;
        cin>>idx>>val;
        updateSegTree(seg,1, 0, n-1, idx-1, val, treelvl);

        cout<<seg[1]<<endl;
    }
    return 0;
}