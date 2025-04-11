#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for (int i = a; i < b; i++)

bool divisors(int n, int m){
    if(m==1 || n==1) return false;
    if(m>=n) return true;
    for (int i = 2; i <= sqrt(n); i++){
        if (n%i == 0){
            if (n/i == i){
                if(i<=m) return true;
            }
            else{
                if((i<=m) || ((n/i)<=m)) return true;
            }
        }
    }

    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        auto begin = chrono::high_resolution_clock::now();
        int n, m;
        cin >> n >> m;
        bool flag=divisors(n,m);
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}