// #include <bits/stdc++.h>
// using namespace std;
// int main(){ 
//     int t;
//     cin>>t;
//     while(t--){
//         string s;
//         cin>>s;
//         int n = s.length();
//         unordered_map<int,int> sum;
//         int presum=0;
//         int ans=0;
//         sum[0]=0;
//         for(int i=0;i<n;i++){
//             if(s[i]=='(') presum-=1;
//             else presum+=1;
//             ans+=sum[presum];
//             sum[presum]++;
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        vector<int> sum(2*n+1,0);
        int presum=0;
        int ans=0;
        sum[n]=1;
        for(int i=0;i<n;i++){
            if(s[i]=='(') presum++;
            else presum--;
            ans+=sum[presum+n];
            sum[presum+n]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}