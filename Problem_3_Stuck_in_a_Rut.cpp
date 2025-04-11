#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
#define pii pair<int,int>
const int inf = 1e18,mod=1e9+7;


signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,pii>> NC,EC;
    for(int i=0;i<n;i++){
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c=='N') NC.push_back({i,{x,y}});
        else EC.push_back({i,{x,y}});
    }

    sort(NC.begin(),NC.end(), [&](pair<int,pii> &a, pair<int,pii> &b){
        if(a.second.first==b.second.first) return a.second.second < b.second.second;
        return a.second.first < b.second.first;
    });
    sort(EC.begin(),EC.end(), [&](pair<int,pii> &a, pair<int,pii> &b){
        if(a.second.second==b.second.second) return a.second.first < b.second.first;
        return a.second.second < b.second.second;
    });

    vector<int> vis(n,0);
    vector<int> blame(n,0);

    for(int i=0;i<EC.size();i++){
        for(int j=0;j<NC.size();j++){
            if((EC[i].second.second >= NC[j].second.second) && (EC[i].second.first <= NC[j].second.first) && !vis[EC[i].first] && !vis[NC[j].first]){
                int x = NC[j].second.first,y=EC[i].second.second;

                if((x-EC[i].second.first) < (y-NC[j].second.second)){
                    vis[NC[j].first]=1;
                    blame[EC[i].first]+=1+blame[NC[j].first];
                }
                else if((x-EC[i].second.first) > (y-NC[j].second.second)){
                    vis[EC[i].first]=1;
                    blame[NC[j].first]+=1+blame[EC[i].first];
                }

            }
        }
    }


    for(int i=0;i<n;i++) cout<<blame[i]<<endl;


    return 0;
}