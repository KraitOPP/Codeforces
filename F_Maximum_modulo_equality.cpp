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

void buildSegmentTree(vi &tree, vi &arr, int node, int l, int r){
    if(l==r){
        tree[node] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    buildSegmentTree(tree, arr, 2*node, l, mid);
    buildSegmentTree(tree, arr, 2*node+1, mid+1, r);
    tree[node] = __gcd(tree[2*node], tree[2*node+1]);
}

int query(vi &tree, int node, int l, int r, int ql, int qr){
    if(l>qr || r<ql) return 0;
    if(l>=ql && r<=qr) return tree[node];
    int mid = (l+r)/2;
    return __gcd(query(tree, 2*node, l, mid, ql, qr), query(tree, 2*node+1, mid+1, r, ql, qr));
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,q;
        cin>>n>>q;
        vi a(n), arr(n-1);
        inp(a,n);
        if(n==1){
            while(q--){
                int l,r;
                cin>>l>>r;
                cout<<0<<" ";
            }
            cout<<endl;
            continue;
        }
        for(int i=1;i<n;i++){
            arr[i-1]=abs(a[i]-a[i-1]);
        }
        vi segTree(4*n,0);
        buildSegmentTree(segTree, arr, 1, 0, n-2);
        while(q--){
            int l,r;
            cin>>l>>r;
            l--,r--;
            if(l==r) cout<<0<<" ";
            else cout<<query(segTree, 1, 0, n-2, l, r-1)<<" ";
        }
        cout<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}