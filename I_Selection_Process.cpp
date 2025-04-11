#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for(int i=a;i<b;i++)

void SieveOfEratosthenes(vector<bool> &prime)
{
    int n = prime.size();
    prime[1]=prime[0]=false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<bool> prime(100005,true);
    SieveOfEratosthenes(prime);


    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    vector<vector<int>> dp(n+1, vector<int>(32, 0));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 30; j++){
            dp[i+1][j] = dp[i][j];
            if(((1<<j)&a[i]) && prime[a[i]]==false) dp[i+1][j]++;
        }
    }
    
    while(q--){
        int l, r, k;
        cin >> l >> r >> k;
        cout << dp[r][k-1] - dp[l-1][k-1] << endl;
    }
    
    return 0;
}
