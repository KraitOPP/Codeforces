#include<bits/stdc++.h>
using namespace std;
int N = 2e5;
long long M = 1e9 + 7; 
vector<long long>fact(N+1);
vector<long long>invfact(N+1);
#define int long long

int exp(int x, int n, int m) {
	assert(n >= 0);
	x %= m; 
	int res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}
	return res;
}

signed main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    vector<int>v(n);
    // unordered_map<int,int>mp;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        // mp[v[i]]++;
        sum=sum+v[i];
    }
    // vector<int>v1;
    int res=0;
    for(int i=0;i<n;i++){
        res=(res + (v[i]*(sum-v[i]))%M)%M;
    }
    // unordered_map<int,int>mpp;
    // for(auto j:mp){
    //     if(j.second > 1){
    //         mpp[j.first*j.first] = ((j.second*(j.second - 1)))/2;
    //     }
    //     v1.push_back(j.first);
    // }

    // for(int i=0;i<v1.size();i++){
    //     for(int j=i+1;j<v1.size();j++){
    //         mpp[v1[i]*v1[j]] = mpp[v1[i]*v1[j]] + mp[v1[i]]*mp[v1[j]];
    //     }
    // }
    int nval = (n*(n-1))%M;
    // int topval = 0;
    // for(auto j:mpp){
    //     topval = (topval + (j.second*j.first)%M)%M;
    // }
    nval = exp(nval,M-2,M);
    int ans = (res*nval)%M;
    cout<<ans<<endl;
   }
}