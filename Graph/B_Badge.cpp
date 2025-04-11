#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inp(a,n) for(int i=0;i<n;i++) cin>>a[i];
#define vi vector<int>
#define ll long long
const int inf = 1e18,mod=1e9+7;
vector<int> p,res;

void fillUp(int curr, int a){
    while(curr!=a){
        res[curr] = res[a];
        curr = p[curr];
    }
}

void solve(int curr){
    int a=p[curr],b=p[p[curr]];
    while(a!=b){
        if(res[a]!=-1){
            fillUp(curr,a);
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

    int cycle_start=a;
    a=curr;
    while(a!=cycle_start){
        res[a] = cycle_start;
        a=p[a];
    }

    a=cycle_start;
    do{
        res[a] = a;
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
    res = vector<int>(n+1,-1);
    for(int i=1;i<=n;i++) cin>>p[i];

    for(int i=1;i<=n;i++){
        if(res[i]==-1){
            solve(i);
        }
    }

    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}