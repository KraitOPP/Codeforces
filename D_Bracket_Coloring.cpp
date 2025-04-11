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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int neg=0,pos=0;
        int sum=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                sum+=1;
            }
            else{
                sum-=1;
            }
            if(sum>0) pos++;
            else if(sum<0) neg++;
        }
        if(sum!=0) cout<<-1<<endl;
        else if((pos!=0 && neg==0) || (pos==0 && neg!=0)){
            cout<<1<<endl;
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }
        else{
            sum=0;
            int prev=-1;
            cout<<2<<endl;
            for(int i=0;i<n;i++){
                if(s[i]=='(') sum++;
                else sum--;
                if(sum>0) cout<<1<<" ";
                else if(sum<0) cout<<2<<" ";
                else cout<<prev<<" ";
                if(sum>0) prev=1;
                else prev=2;
            }
            cout<<endl;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}