#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int x = abs(mp['N']-mp['S']);
        int y = abs(mp['E']-mp['W']);
        if(x%2 || y%2) cout<<"NO"<<endl;
        else if(n==2 && x==0 && y==0) cout<<"NO"<<endl;
        else{
                int north = mp['N']/2;
                int south = mp['S']/2;
                int east = mp['E']/2;
                int west = mp['W']/2;
                for(int i=0;i<n;i++){
                    if(s[i]=='N' && north){
                         s[i]='R';
                         north--;
                    }
                    else if(s[i]=='S' && south){
                         s[i]='R';
                         south--;
                    }
                    else if(s[i]=='E' && east){
                        s[i]='R';
                        east--;
                    }
                    else if(s[i]=='W' && west){
                        s[i]='R';
                        west--;
                    }
                }
                for(int i=0;i<n;i++){
                    if(s[i]!='R') s[i]='H';
                }
                cout<<s<<endl;
            }
        }
    return 0;
}