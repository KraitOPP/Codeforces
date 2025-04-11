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
        int n,k;
        cin>>n>>k;
        string s1,s2;
        cin>>s1>>s2;
        bool flag=true;
        vector<int> a;
        vector<char> b;
        int i=0;
        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            };
            int j=i+1;
            while(j<n && s2[i]==s2[j]){
                j++;
            }
            if((j-i)!=k){
                flag=false;
                break;
            }
            else{
                a.push_back(i+1);
                b.push_back(s2[i]);
            }
            i=j;
        }
        if(flag==false) cout<<-1<<endl;
        else{
            cout<<a.size()<<endl;
            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" "<<b[i]<<endl;
            }
        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}