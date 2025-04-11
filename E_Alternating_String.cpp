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
        if(n<=1) cout<<n<<endl;
        else if(n%2==0){
            vector<int> eve(26,0),od(26,0);
            for(int i=0;i<n;i++){
                if(i%2==1){
                    od[s[i]-'a']++;
                }
                else eve[s[i]-'a']++;
            }
            int mx1=0,mx2=0;
            for(int i=0;i<26;i++) mx1 = max(mx1,od[i]);
            for(int i=0;i<26;i++) mx2 = max(mx2,eve[i]);
            cout<<n-mx1-mx2<<endl;
        }
        else{
            vector<vector<int>> od(n/2+1,vector<int>(26,0));
            vector<vector<int>> eve(n/2,vector<int>(26,0));
            od[0][s[0]-'a']++;
            eve[0][s[1]-'a']++;
            for(int i=2;i<n;i+=2){
                for(int j=0;j<26;j++){
                    od[i/2][j] = od[i/2-1][j];
                }
                od[i/2][s[i]-'a']++;
            }
            for(int i=3;i<n;i+=2){
                for(int j=0;j<26;j++){
                    eve[i/2][j] = eve[i/2-1][j];
                }
                eve[i/2][s[i]-'a']++;
            }


            int mx=0;
            for(int i=0;i<n;i++){
                int currod=0,currev=0;
                for(int j=0;j<26;j++){
                    if(i%2==0){
                        int prvod = (i/2-1>=0) ? od[i/2-1][j]:0;
                        int nxod = (i/2 < n/2) ? eve[i/2][j]:0;
                        currod = max(currod,prvod+nxod);

                        int prvev = (i/2-1>=0) ? eve[i/2-1][j]:0;
                        int nxev = (i/2 < n/2) ? od[i/2+1][j]:0;
                        currev = max(currev,prvev+nxev);
                    }
                    else{
                        int prvod = (i/2>=0) ? od[i/2][j]:0;
                        int nxod = (i/2+1 < n/2) ? eve[i/2+1][j]:0;
                        currod = max(currod,prvod+nxod);

                        int prvev = (i/2-1>=0) ? eve[i/2-1][j]:0;
                        int nxev = (i/2 < n/2) ? od[i/2+1][j]:0;
                        currev = max(currev,prvev+nxev);
                    }
                }
                cout<<currev<<" "<<currod<<endl;
                if((currev+currod) > mx){
                    mx = currev+currod;
                }
            }
            cout<<n-1-mx<<endl;

        }


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}