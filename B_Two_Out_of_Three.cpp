#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int n;
        cin>>n;
        int a[n];
        int b[n]={0};
        map<int,int> mp;
        int c=0;
        int x1=-1,x2=-1;
        loop(i,0,n){
            cin>>a[i];
            mp[a[i]]++;
            if(mp[a[i]]==2){
                 c++;
                 if(x1==-1) x1=a[i];
                 else if(x2==-1) x2=a[i];
            }
        }
        if(c<2) cout<<-1<<endl;
        else{
            int f1=1;
            int f2=1;
            loop(i,0,n){
                if(a[i]==x1){
                    if(f1){
                        cout<<1<<" ";
                        f1=0;
                    }
                    else cout<<2<<" ";
                }
                else if(a[i]==x2){
                    if(f2){
                        cout<<1<<" ";
                        f2=0;
                    }
                    else cout<<3<<" ";
                }
                else cout<<"1 ";
            }
            cout<<endl;
        }

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}   