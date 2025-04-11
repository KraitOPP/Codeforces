#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define vpii vector<pair<int,int>>
#define pii pair<int,int>
#define ll long long
const int inf = 1e18,mod=1e9+7;

class TrieNode{
    public:
    TrieNode* child[26];
    int isEnd;
    TrieNode(){
        isEnd = 0;
        for(int i=0;i<26;i++){
            child[i] = NULL;
        }
    }
};

void insert(TrieNode* root, string s){
    TrieNode* curr = root;
    for(int i=0;i<s.length();i++){
        if(curr->child[s[i]-'a'] == NULL){
            curr->child[s[i]-'a'] = new TrieNode();
        }
        curr = curr->child[s[i]-'a'];
    }
    curr->isEnd+=1;
}

void solve(TrieNode* root, int curr, int &res){
    if(root->isEnd!=0){
        res+=root->isEnd*curr+root->isEnd*(root->isEnd-1)/2;
        curr+=root->isEnd;
    }
    for(int i=0;i<26;i++){
        if(root->child[i] != NULL){
            solve(root->child[i], curr, res);
        }
    }
}

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
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            insert(root, s);
        }
        int res = 0;
        solve(root, 0, res);
        cout<<res<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}