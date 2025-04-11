#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n , k; 
	    cin>>n>>k;
	    vector<vector<int>> a(k);
	    for(int i = 0; i < k; i++){
	        int l,r,m; 
	        cin>>l>>r>> m;
	        a[i].push_back(l);
	        a[i].push_back(r);
	        a[i].push_back(m);
	    }
	    vector<vector<int>> b(n);
	    vector<int> res(n,n);
	    vector<set<int>> x(n);
	    bool flg=true;
	    for(int i=0;i<k;i++){
	        int l=a[i][0],r=a[i][1];
	        for(int j=l-1;j<=r-1;j++){
	           if(x[j].find(a[i][2])==x[j].end()){
	               b[j].push_back(a[i][2]);
	               x[j].insert(a[i][2]);
	           }
	        }
	    }
	    for(int i=0;i<n;i++){
	        sort(b[i].begin(),b[i].end(), greater<int>());
	        for(int j=0;j<b[i].size();j++){
	            if(res[i]==b[i][j]){
	                res[i]--;
	                if(res[i]<1) flg=false;
	            }
	            else break;
	        }
	    }
	    if(flg){
	        for(int i=0;i<n;i++){
	            cout<<res[i]<<" ";
	        }
	        cout<<endl;
	    }
	    else cout<<-1<<endl;
	}

}