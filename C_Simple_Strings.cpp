#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        auto begin = chrono::high_resolution_clock::now();
        string s;
        cin>>s;
        int n=s.length();
        int cnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                if(cnt>1){
                    int j=i-cnt+1;
                    while(j<i){
                        int x=s[j-1]-'a';
                        x=(x+1)%26;
                        s[j]='a'+x;
                        if((j+1)<n && s[j]==s[j+1]){
                            x=(x+1)%26;
                            s[j]='a'+x;
                        }
                        j+=2;
                    }
                }
                cnt=1;
            }
        }
        if(cnt>1){
            int j=n-cnt+1;
            while(j<n){
                int x=s[j-1]-'a';
                x=(x+1)%26;
                s[j]='a'+x;
                j+=2;
            }
        }
        cout<<s<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    return 0;
}