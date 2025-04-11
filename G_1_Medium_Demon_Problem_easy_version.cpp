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



signed main() { 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        vi indeg(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]--;
            indeg[a[i]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        int res=0;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int front = q.front();
                q.pop();
                indeg[a[front]]--;
                if(indeg[a[front]]==0){
                    q.push(a[front]);
                }
            }
            res++;
        }

        cout<<res+2<<endl;
    }
    return 0;
}
