#include <bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        map<pair<int,int>,vector<int>> mp1;
        map<pair<int,int>,vector<int>> mp2;
        map<pair<int,int>,vector<int>> mp3;
        for(int i=0;i<n-2;i++){
            mp1[{a[i],a[i+1]}].push_back(a[i+2]);
            mp2[{a[i],a[i+2]}].push_back(a[i+1]);
            mp3[{a[i+1],a[i+2]}].push_back(a[i]);
        }

        long long ans=0;
        for(auto itr : mp1){
            unordered_map<int,int> cnt;
            for(auto itr2 : itr.second){
                cnt[itr2]++;
            }
            long long x = itr.second.size();
            for(auto itr2 : itr.second){
                ans+=x-cnt[itr2];
            }
        }
        for(auto itr : mp2){
            unordered_map<int,int> cnt;
            for(auto itr2 : itr.second){
                cnt[itr2]++;
            }
            long long x = itr.second.size();
            for(auto itr2 : itr.second){
                ans+=x-cnt[itr2];
            }
        }
        for(auto itr : mp3){
            unordered_map<int,int> cnt;
            for(auto itr2 : itr.second){
                cnt[itr2]++;
            }
            long long x = itr.second.size();
            for(auto itr2 : itr.second){
                ans+=x-cnt[itr2];
            }
        }
        cout<<ans/2<<endl;
    }
    return 0;
}