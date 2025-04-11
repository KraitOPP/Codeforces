uujiko#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

int zeroes(int n){
    int cnt=0;
    while(n%10==0 && n!=0){
        cnt++;
        n/=10;
    }

    return cnt;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n, m;
        cin >> n >> m;
        int n0 = n;
        int cnt2=0,cnt5=0;
        while(n%5==0) cnt5++,n/=5;
        while(n%2==0) cnt2++,n/=2;
        int k=1;
        while(cnt2<cnt5 && k*2<=m) k*=2,cnt2++;
        while(cnt2>cnt5 && k*5<=m) k*=5,cnt5++;
        while(k*10<=m) k*=10;

        cout<<n0*k*(m/k)<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    return 0;
}
