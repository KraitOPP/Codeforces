#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;

        int for2 = (y+1)/2;
        int rem = for2*15 - y*4;

        int rem2 = x-rem;
        
        if(rem2<=0) cout<<for2<<endl;
        else cout<<for2+ceil(rem2/15.0)<<endl;
    }
    return 0;
}