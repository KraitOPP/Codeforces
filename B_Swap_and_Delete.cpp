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
        string s;
        cin>>s;
        int n=s.length();
        int cnt0=0;
        int cnt1=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') cnt0++;
            else cnt1++;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(cnt1==0){
                    ans=n-i;
                    break;
                }
                else cnt1--;
            }
            else{
                if(cnt0==0){
                    ans=n-i;
                    break;
                }
                else cnt0--;
            }
        }
        cout<<ans<<endl;
 
 
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
 }