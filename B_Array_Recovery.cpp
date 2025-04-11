#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i = a; i < b; i++)

int solve(vector<int> &a, int index, int prev, int n, vector<int> temp, vector<vector<int>> &dp) {
    if (index >= n || prev<0) {
        if (temp.size() == n){ 
            return true;
        }
        return false;
    }
    if(dp[index][prev]!=-1) return dp[index][prev];
    if(a[index]==0){
        temp.push_back(prev);
        return dp[index][prev] = solve(a,index+1,prev,n,temp,dp);
        
    }
    int f1=0;
    int f2=0;

    if ((prev + a[index]) <= 100) {
        temp.push_back(prev + a[index]);
        f1 = solve(a, index + 1, prev + a[index], n, temp,dp);
        temp.pop_back();
    }
    if ((prev - a[index]) >= 0) {
        temp.push_back(prev - a[index]);
        f2 = solve(a, index + 1, prev - a[index], n, temp,dp);
        temp.pop_back();
    }
    vector<int> tmp;
    if(f1 && f2) return dp[index][prev] = false;
    else return dp[index][prev] = f1||f2;
}

signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        auto begin = chrono::high_resolution_clock::now();
        
        int n;
        cin >> n;
        vector<int> a(n);
        loop(i, 0, n) cin >> a[i];
        vector<vector<int>> dp(100,vector<int>(101,-1));
        vector<int> temp;
        int f = solve(a, 0, 0, n, temp,dp);
        if (f==1) {
            int prev=0;
            for(int i=0;i<n;i++){
                if ((prev + a[i]) <= 100) {
                    cout<<prev+a[i]<<" ";
                    prev=prev+a[i];
                }
                else{
                    cout<<prev-a[i];
                    prev=prev-a[i];
                }
            }
            cout<<endl;
        } else {
            cout << -1 << endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
