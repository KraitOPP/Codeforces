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
        int n,w;
        cin>>n>>w;
        vector<int> a(20,0);
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            a[(int)log2(tmp)]++;            
        }

        int height=1,space=w;
        for(int i=0;i<n;i++){
            int large=-1;
            for(int i=19;i>=0;i--){
                if((1<<i)<=space && a[i]>0){
                    large=i;
                    break;
                }
            }

            if(large==-1){
                space=w;
                height++;
                for(int i=19;i>=0;i--){
                    if((1<<i)<=space && a[i]>0){
                        large=i;
                        break;
                    }
                }
            }
            space-=1<<large;
            a[large]-=1;
        }

        cout<<height<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}