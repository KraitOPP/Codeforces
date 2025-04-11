#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        
        int n, k;
        cin >> k >> n;
        
        int x = n - k;  // the number of gaps we can fill with increments
        int y = 0;
        int i = 1;

        while(k > 0){
            cout << i << " ";
            k--;

            if(k > 0){
                int remaining_positions = k;
                int remaining_values = n - i;
                
                if(remaining_values - y - 1 >= remaining_positions - 1){
                    y++;
                    i += y;
                } else {
                    i++;
                }
            }
        }
        
        cout << endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
