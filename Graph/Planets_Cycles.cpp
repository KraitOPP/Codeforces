#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
vector<int> p,res, revp;


void solve(int curr){
    int a=p[curr],b=p[p[curr]];
    while(a!=b){
        if(res[a]!=-1){
            int x=curr,len=0;
            while(x!=a){
                len++;
                x=p[x];
            }
            x=curr;
            while(x!=a){
                res[x]=res[a]+len;
                x=p[x];
                len--;
            }
            return;
        }
        a=p[a];
        b = p[p[b]];
    }

    a=curr;
    while(a!=b){
        b=p[b];
        a=p[a];
    }
    int cyclen=0;
    int cycle_start=a;
    
    a=cycle_start;
    do{
        cyclen++;
        a=p[a];
    } while(a!=cycle_start);

    a=curr;
    int len=0;
    while(a!=cycle_start){
        len++;
        a=p[a];
    }

    a=curr;
    while(a!=cycle_start){
        res[a] = len+cyclen;
        a=p[a];
        len--;
    }

    a=cycle_start;
    do{
        res[a] = cyclen;
        a=p[a];
    } while(a!=cycle_start);

}

signed main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    p = vector<int>(n+1);
    revp = vector<int> (n+1);
    res = vector<int>(n+1,-1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        revp[p[i]]=i;
    }

    for(int i=1;i<=n;i++){
        if(res[i]==-1){
            solve(i);
        }
    }

    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}