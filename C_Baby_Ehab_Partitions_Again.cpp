#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF 1e18
#define endl "\n"
#define pb push_back
#define vi vector<int>

typedef long long ll;

#define int long long

signed main() {
    fastio();
    
    int n;
    cin>>n;
    vi a(n);
    
    int sum=0;
    for (int i=0; i<n; i++) {
        cin>>a[i];
        sum+=a[i];
    }

    if (sum%2==1) {
        cout<<0<<endl;
        return 0;
    }

    int target=sum/2;
    
    vector<int> dp(target+1, 0);
    dp[0] = 1;

    for(int num:a) {
        for(int j=target; j>=num; j--) {
            if(dp[j-num]){
                dp[j]=1;
            }
        }
    }

    if(dp[target]==0) {
        cout<<0<<endl;
        return 0;
    }

    int res=LLONG_MAX, idx=-1;
    for (int i=0; i<n; i++) {
        int cnt=0, num=a[i];
        while(num%2==0) {
            num/=2;
            cnt++;
        }
        if(cnt<res) {
            res=cnt;
            idx=i;
        }
    }

    cout<<1<<endl;
    cout<<idx+1<<endl;
    return 0;
}
