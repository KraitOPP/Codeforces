#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define loop(i, a, b) for(int i=a;i<b;i++)

signed main(){ 
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n>>m;
    vector<int> mp(26,0);
    int cnt=1;
    for(int i=0;i<18;i++){
        if(i%3==0) cnt++;
        mp[i]=cnt;
    }
    mp[18]=7,mp[19]=8,mp[20]=8,mp[21]=8;
    mp[22]=9,mp[23]=9,mp[24]=9,mp[25]=9;
    vector<string> s;
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        s.push_back(tmp);
    }
    vector<string> q;
    map<string,int> res;
    for(int i=0;i<m;i++){
        string c;
        cin>>c;
        res[c]=0;
        q.push_back(c);
    }
    for(auto str: s){
        string tmp="";
        for(auto c:str){
            tmp+=to_string(mp[c-'a']);
            if(res.find(tmp)!=res.end()){
                res[tmp]++;
            }
        }
    }
    for(auto ans: q){
        cout<<res[ans]<<endl;
    }


    return 0;
}