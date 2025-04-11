#include <bits/stdc++.h>
using namespace std;
include <ext/pb_ds/assoc_container.hpp>

include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template using ordered_set = tree<T, null_type, less, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

/*************  ✨ Codeium Command ⭐  *************/
/**
 * @brief Given a range [l, r] and an integer k, find the
 * maximum sum of elements in the range which can be divided
 * into k groups such that each group has either one or two
 * elements.
 * @param l The lower bound of the range.
 * @param r The upper bound of the range.
 * @param k The number of groups to divide the range into.
 * @return A pair containing the maximum sum of elements and
 * the number of elements in the range that were included in
 * the k groups.
 */
/******  a399ae52-f64e-40b4-953f-101368a033d3  *******/
pair<int,int> solve(int l, int r, int k){
    if(l>r || (r-l+1)<k) return {0,0};
    if(l==r) return {1,l};
    
    int mid = l+(r-l)/2;
     if((r-l+1)%2){  
        pair<int,int> left = solve(l, mid-1, k);
        int s = left.first;
        int ele = left.second;

        int sum = mid + 2*s + mid*ele;
        int elements = 2*ele + 1; 
        return {sum, elements};
    } 
    else{ 
        pair<int,int> left = solve(l, mid, k);
        int s = left.first;
        int ele = left.second;

        int sum = 2*s + mid*ele;
        int elements = 2*ele;
        return {sum, elements};
    }
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
        int res=solve(1,n,k).first;

        cout<<res<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}