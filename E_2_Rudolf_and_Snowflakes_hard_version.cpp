#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

const long long mx = 1e18;
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
        bool flag = false;
        
        for(int i = 3; i <= 62; i++){
            int s = 2;
            int e = powl(mx,1.0/(i-1));
            while(s <= e){
                int mid=s+(e-s)/2;
                if((1+mid+mid*mid) > n){
                    e=mid-1;
                    continue;
                }
                int x=0;
                for(int j=0;j<i;j++){
                    if(x>=n || pow(mid,j)>n){
                        x=n+1;
                        break;
                    }
                    x=x*mid+1;
                }
                if(x==n){
                    flag = true;
                    break;
                }
                else if(x<n){
                    s = mid + 1;
                }
                else{
                    e=mid-1;
                }
            }
            if(flag) break;
        }
        
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds." << endl;
    }
    
    return 0;
}
