#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

int solve(int x){
    if(x==1 || x==0) return x;
    int mn = floor(log2(x));
    mn = 1<<mn;

    return 1+solve(x%mn);
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        int x;
        cin>>x;

        cout<<solve(x)<<endl;
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}