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
        vi a(n+1);
        a[0]=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        a.push_back(0);
        vpii idx;
        int s=0;
        for(int i=0;i<=n+1;i++){
            if(a[i]==0){
                if(s!=i){
                    idx.push_back({s,i-1});
                }
                s=i+1;
            }
        }
        if(idx.size()==0){
            cout<<n<<" "<<0<<endl;
            continue;
        }
        int mxcnt2=-1, rems=0, reme=0;
        for(int i=0;i<idx.size();i++){
            int cnt2=0, cntn=0;
            for(int j=idx[i].first;j<=idx[i].second;j++){
                if(a[j]<0) cntn++;
                if(a[j]==-2 || a[j]==2) cnt2++;
            }
            if(cntn%2==0 && cnt2>mxcnt2){
                mxcnt2=cnt2;
                rems=idx[i].first;
                reme=idx[i].second;
            }
            int start=-1,end=-1, stcnt2=0, ecnt2=0;
            for(int j=idx[i].first;j<=idx[i].second;j++){
                if(a[j]==2 || a[j]==-2) stcnt2++;
                if(a[j]<0){
                    start=j;
                    break;
                }
            }
            for(int j=idx[i].second;j>=idx[i].first;j--){
                if(a[j]==2 || a[j]==-2) ecnt2++;
                if(a[j]<0){
                    end=j;
                    break;
                }
            }
            if((cnt2-stcnt2)>mxcnt2){
                mxcnt2=cnt2-stcnt2;
                rems=start+1;
                reme=idx[i].second;
            }
            if((cnt2-ecnt2)>mxcnt2){
                mxcnt2=cnt2-ecnt2;
                rems=idx[i].first;
                reme=end-1;
            }
        }
        if(rems>reme) cout<<n<<" "<<0<<endl;
        else cout<<rems-1<<" "<<n-reme<<endl;


        auto end = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
        cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds."<<endl;
    }
    return 0;
}