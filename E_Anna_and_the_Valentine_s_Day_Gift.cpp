#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n,m;
        cin>>n>>m;
        vector<string> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> zeroes(n,0);
        int res=0;
        for(int i=0;i<n;i++){
            int x = a[i].size();
            int cnt=0;
            for(int j=x-1;j>=0&&a[i][j]=='0';j--){
                cnt++;
            }
            res+=x-cnt;
            zeroes.push_back(cnt);
        }
        sort(zeroes.rbegin(),zeroes.rend());
        for(int i=1;i<n;i+=2) res+=zeroes[i];
        if((res-1)>=m) cout<<"Sasha"<<endl;
        else cout<<"Anna"<<endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}