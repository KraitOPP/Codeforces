#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;


signed main(){ 

    int k;
    cout<<"next 0 1"<<endl;
    cin>>k;
    for(int i=0;i<k;i++){
        string s;
        cin>>s;
    }
    cout<<"next 1"<<endl;
    cin>>k;
    for(int i=0;i<k;i++){
        string s;
        cin>>s;
    }
    while(k!=2){
        cout<<"next 0 1"<<endl;
        cin>>k;
        for(int i=0;i<k;i++){
            string s;
            cin>>s;
        }
        cout<<"next 1"<<endl;
        cin>>k;
        for(int i=0;i<k;i++){
            string s;
            cin>>s;
        }
    }

    while(k!=1){
        cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
        cin>>k;
        for(int i=0;i<k;i++){
            string s;
            cin>>s;
        }
    }

    cout<<"done"<<endl;

    return 0;
}