#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int t;
    cin >> t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        
        int n;
        cin >> n;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) 
            cin >> a[i];

        vector<vector<int>> pre(n+1, vector<int>(30, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 30; j++){
                int num = 1LL << j;
                pre[i][j] = pre[i-1][j];
                if((num & a[i]) != 0) pre[i][j]++;
            }
        }
        
        int q;
        cin >> q;
        while(q--){
            int l, k;
            cin >> l >> k;
            int res = -1;
            int s = l, e = n;

            while(s <= e){
                int mid = s + (e - s) / 2;
                int len = mid - l + 1;
                int x=0;
                for(int i = 0; i < 30; i++){
                    int num = 1LL << i;
                    if(((pre[mid][i] - pre[l-1][i]) >= len)){
                        x+=num;
                    }
                }
                if(x>=k){
                    res = mid;
                    s = mid + 1;
                }
                else e = mid - 1;
            }

            cout << res << " ";
        }
        cout << endl;
    }
    
    return 0;
}
