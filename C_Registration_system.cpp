#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<string> s(n);
    map<string,int> mp;
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(mp[s[i]]==0){
            cout<<"OK"<<endl;
            mp[s[i]]++;
        }
        else{
            cout<<s[i]<<mp[s[i]]<<endl;
            mp[s[i]]++;
        }
    }
    return 0;
}