#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    auto begin = chrono::high_resolution_clock::now();
    string vow = "AEIOUYaeiouy";
    string s;
    cin>>s;
    int n=s.length();
    loop(i,0,n){
         int isvow=0;
            loop(j,0,12){
             if(s[i]==vow[j]){
                    isvow=1;
                 break;
             }
        }
         if(isvow) continue;
         else{
            char c = tolower(s[i]);
             cout<<"."<<c;
         }
     }
     cout<<endl;
     auto end = chrono::high_resolution_clock::now();
     auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
     cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
} 