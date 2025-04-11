#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("folding.in", "r", stdin);
    freopen("folding.out", "w", stdout);
	double a,b,c,d;
	cin>>a>>b>>c>>d;
    double A=a;
    double B=b;
    int ans=INT_MAX;
    int k1=0,f1=0;
   
    while(a>=c)
    {
         if(a==c) f1=1;
        a/=2.0;
        k1++;
    }
    int k2=0,f2=0;        
   
    while(A>=d)
    {
         if(A==d) f2=1;
        A/=2.0;
        k2++;
    }
    int k3=0,f3=0;        
   
    while(b>=c)
    {
         if(b==c) f3=1;
        b/=2.0;
        k3++;
    }
    int k4=0,f4=0;       
   
    while(B>=d)
    {
         if(B==d) f4=1;
        B/=2.0;
        k4++;
    }
    //cout<<k1<<k2<<k3<<k4<<endl;
    if(k1!=0 && k4!=0)
    {
        if(f1==1)
        {
            k1--;
        }
        if(f4==1) k4--;
         ans=min(ans,k1+k4);
    }
   
    if(k2!=0 && k3!=0)
    {
        if(f3==1) k3--;
        if(f2==1) k2--;
        ans=min(ans,k2+k3);
    }
    if(ans!=INT_MAX)
    cout<<ans<<endl;
    if(ans==INT_MAX) cout<<-1<<endl;
    return 0;
}