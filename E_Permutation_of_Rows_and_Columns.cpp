#include <bits/stdc++.h>
using namespace std;
#define int long long
#define loop(i, a, b) for(int i=a;i<b;i++)

bool cmp(vector<int> a, vector<int> b){
    return a[0]<b[0];
}

bool solve(vector<vector<int>> a, vector<vector<int>> b, int m, int n){
    map<int,int> row;
    map<int,int> col;

    loop(i,0,m){
        loop(j,0,n){
            row[a[i][j]]=i;
            col[a[i][j]]=j;
        }
    }
    map<pair<int,int>,int> rcnt;
    map<pair<int,int>,int> ccnt;
    loop(i,0,m){
        loop(j,0,n){
            if(row[b[i][j]]!=i) rcnt[{i,row[b[i][j]]}]++;
            if(col[b[i][j]]!=j) ccnt[{j,col[b[i][j]]}]++;
        }
    }
    for(auto itr : rcnt){
        if(itr.second!=n) return false;
    }
    for(auto itr : ccnt){
        if(itr.second!=m) return false;
    }
    
    return true;
}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        auto begin = chrono::high_resolution_clock::now();
        int m,n;
        cin>>m>>n;
        vector<vector<int>> a(m,vector<int>(n));
        vector<vector<int>> b(m,vector<int>(n));
        loop(i,0,m){
            loop(j,0,n) cin>>a[i][j];
        }
        loop(i,0,m){
            loop(j,0,n) cin>>b[i][j];
        }

        if(!solve(a,b,m,n)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr<<"Time measured: "<<elapsed.count()*1e-9<<" seconds."<<endl;
    }
    return 0;
}