#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){ 
    int x;
    cin>>x;
    while(x--){
        int t,p;
        cin>>p>>t;
        int n = p+t+1;
        int P[n],T[n];
        for(int i=0;i<n;i++) cin>>P[i];
        for(int i=0;i<n;i++) cin>>T[i];

        int psum=0,tsum=0;
        int t1=t,p1=p;
        int i=0;
        for(i=0;i<n;i++){
            if(p==0 || t==0) break;
            if(P[i] > T[i]){
                psum+=P[i];
                p--;
            }
            else{
                tsum+=T[i];
                t--;
            }
        }
        int index=-1;
        if(p==0){
            for(;i<n;i++){
                if((index==-1) && (P[i] > T[i])){
                    index=i;
                }
                tsum+=T[i];
            }
            if(index==-1) index=n-1;
            for(int i = 0;i<n;i++){
                int tsumtmp = tsum;
                int psumtmp = psum;
                if(P[i] > T[i] && i<index){
                    tsumtmp-=T[index];
                    psumtmp+=P[index]-P[i];
                    cout<<psumtmp+tsumtmp<<" ";
                }
                else{
                    tsumtmp-=T[i];
                    cout<<psumtmp+tsumtmp<<" ";
                }
            }
        }
        else{
            for(;i<n;i++){
                if((index==-1) && (P[i] < T[i])){
                    index=i;
                }
                psum+=P[i];
            }
            if(index==-1) index=n-1;
            for(int i = 0;i<n;i++){
                int tsumtmp = tsum;
                int psumtmp = psum;
                if(P[i] < T[i] && i<index){
                    psumtmp-=P[index];
                    tsumtmp+=T[index]-T[i];
                    cout<<psumtmp+tsumtmp<<" ";
                }
                else{
                    psumtmp-=P[i];
                    cout<<psumtmp+tsumtmp<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}