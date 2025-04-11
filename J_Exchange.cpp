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
        int n,q;
        cin>>n>>q;
        deque<pair<int,int>> Bq;
        deque<pair<int,int>> Wq;
        
        for(int i=0;i<n;i++){
            int id,quan;
            char c;
            cin>>id>>c>>quan;
            if(c=='W'){
                Wq.push_back({id,quan});
            }
            else{
                Bq.push_back({id,quan});
            }
        }
        map<pair<int,int>,int> mp;
        while(!Wq.empty() && !Bq.empty()){
            pair<int,int> wtop = Wq.front();
            pair<int,int> btop = Bq.front();
            Wq.pop_front();
            Bq.pop_front();
            if(wtop.second > btop.second){
                wtop.second-=btop.second;
                Wq.push_front(wtop);
                mp[{wtop.first,btop.first}]+=btop.second;
                mp[{btop.first,wtop.first}]+=btop.second;
            }
            else if(wtop.second < btop.second){
                btop.second-=wtop.second;
                Bq.push_front(btop);
                mp[{wtop.first,btop.first}]+=wtop.second;
                mp[{btop.first,wtop.first}]+=wtop.second;
            }
            else{
                mp[{wtop.first,btop.first}]+=wtop.second;
                mp[{btop.first,wtop.first}]+=wtop.second;
            }
        }

        while(q--){
            int a,b;
            cin>>a>>b;
            cout<<mp[{a,b}]<<endl;
        }
        
        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}