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
        int n;
        cin>>n;
        string s;
        cin>>s;

        set<string> present;

        for(int i = 0; i < n; i++){
            string tmp = s.substr(i, 1);
            present.insert(tmp);
        }

        for(int i = 0; i < n-1; i++){
            string tmp = s.substr(i, 2);
            present.insert(tmp);
        }

        for(int i = 0; i < n-2; i++){
            string tmp = s.substr(i, 3);
            present.insert(tmp);
        }

        string ans = "";

        for(char c = 'a'; c <= 'z'; c++){
            string tmp = "";
            tmp += c;
            if(present.find(tmp) == present.end()){
                ans = tmp;
                break;
            }
        }

        if(ans == ""){
            for(char c1 = 'a'; c1 <= 'z'; c1++){
                for(char c2 = 'a'; c2 <= 'z'; c2++){
                    string tmp = "";
                    tmp += c1;
                    tmp += c2;
                    if(present.find(tmp) == present.end()){
                        ans = tmp;
                        break;
                    }
                }
                if(ans != "") break;
            }
        }

        if(ans == ""){
            for(char c1 = 'a'; c1 <= 'z'; c1++){
                for(char c2 = 'a'; c2 <= 'z'; c2++){
                    for(char c3 = 'a'; c3 <= 'z'; c3++){
                        string tmp = "";
                        tmp += c1;
                        tmp += c2;
                        tmp += c3;
                        if(present.find(tmp) == present.end()){
                            ans = tmp;
                            break;
                        }
                    }
                    if(ans != "") break;
                }
                if(ans != "") break;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
