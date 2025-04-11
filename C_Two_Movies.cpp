#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        
        int x = 0, y = 0;
        int expos = 0, exng = 0;
        
        for(int i = 0; i < n; i++){
            if(a[i] == 1 && b[i] == 1){
                expos++;
            }
            else if(a[i] == -1 && b[i] == -1){
                exng++;
            }
            else if(a[i] == 1 && (b[i] == 0 || b[i] == -1)){
                x++;
            }
            else if((a[i] == 0 || a[i] == -1) && b[i] == 1){
                y++;
            }
        }
        
        int aa = max(x, y);
        int bb = min(x, y);
        
        while(aa > bb && (exng > 0 || expos > 0)){
            if(exng > 0){
                aa--;
                exng--;
            }
            else if(expos > 0){
                bb++;
                expos--;
            }
        }
        int extra=expos-exng;
        if(extra>=0) cout<<min(aa,bb)+extra/2<<endl;
        else cout<<max(aa,bb)+(extra-1)/2<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
