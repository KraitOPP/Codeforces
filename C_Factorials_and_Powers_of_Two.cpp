#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)
vector<int> a;

void calc(){
    a.push_back(6);
    for(int i=4;i<=14;i++){
        a.push_back(a.back()*i);
    }
}

int solve(int idx, int n){
    if(n == 0) return 0;

    if(n < 0) return INT_MAX;

    int q = n;
    int c = 0;
    while(q){
        c += (q & 1); 
        q/=2;
    }

    if(idx >= a.size()) return c;

    int include = solve(idx+1, n - a[idx]);  
    int exclude = solve(idx+1, n);          
    if (include != INT_MAX) include += 1;

    return min(include, exclude);
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calc();  
    
    int t;
    cin >> t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin >> n;  

        int res = solve(0, n);
        cout << res << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
